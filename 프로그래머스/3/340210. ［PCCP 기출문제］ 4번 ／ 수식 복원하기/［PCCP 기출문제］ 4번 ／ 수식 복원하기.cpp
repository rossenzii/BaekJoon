#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

// ① nToDesc -> nToDec 로 이름 변경
int nToDec(string num, int n){ // n진수 -> 10진수
    int dec = 0;
    for(char c : num){
        dec = dec * n + (c - '0');
    }
    return dec;
}

string decToN(int num, int n){
    if(num == 0) return "0";
    string result = "";
    while(num > 0){
        result = to_string(num % n) + result;
        num /= n; // ② / -> /= 로 수정 (몫 갱신)
    }
    return result;
}

struct Expression{
    string a, op, b, c;
};

vector<string> solution(vector<string> expressions) {
    vector<string> answer; // 여기서 한 번만 선언
    vector<Expression> completes;
    vector<Expression> hints;
    int max_digit = 1; 
    
    for(string exp : expressions){
        stringstream ss(exp);
        string a, op, b, eq, c;
        ss >> a >> op >> b >> eq >> c;
        
        for(char ch : a) max_digit = max(max_digit, ch - '0');
        for(char ch : b) max_digit = max(max_digit, ch - '0');
        if(c != "X"){
            for(char ch : c) max_digit = max(max_digit, ch - '0');
            completes.push_back({a, op, b, c});
        }else{
            hints.push_back({a, op, b, c});
        }
    }

    int min_base = max_digit + 1;
    vector<bool> possible_bases(10, false);
    for(int i = min_base; i <= 9; i++) possible_bases[i] = true;

    for(auto exp : completes){
        for(int base = min_base; base <= 9; base++){
            if(!possible_bases[base]) continue; // ③ possible_base -> possible_bases 로 수정
            int dec_a = nToDec(exp.a, base);
            int dec_b = nToDec(exp.b, base);
            int dec_c = nToDec(exp.c, base);
            int expected = (exp.op == "+") ? (dec_a + dec_b) : (dec_a - dec_b);
            if(expected != dec_c){
                possible_bases[base] = false;
            }
        }
    }

    // ④ vector<string> answer; 중복 선언 삭제
    for(auto exp : hints){
        string final_c = "";
        bool is_confused = false;
        for(int base = min_base; base <= 9; base++){
            if(!possible_bases[base]) continue;
            int dec_a = nToDec(exp.a, base);
            int dec_b = nToDec(exp.b, base);
            // ⑤ expected_dec 뒤에 '=' 추가
            int expected_dec = (exp.op == "+") ? (dec_a + dec_b) : (dec_a - dec_b);
            string current_c = decToN(expected_dec, base); 
            if(final_c == ""){
                final_c = current_c;
            }else if(final_c != current_c){
                is_confused = true;
            }
        }
        
        // 공백 배치 가독성 수정 (? 앞공백 추가)
        if(is_confused){
            answer.push_back(exp.a + " " + exp.op + " " + exp.b + " = ?");
        } else {
            answer.push_back(exp.a + " " + exp.op + " " + exp.b + " = " + final_c);
        }
    }
    
    return answer;
}