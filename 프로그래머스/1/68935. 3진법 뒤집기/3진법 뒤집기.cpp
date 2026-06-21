#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string str_num = "";
    
    // 1. 10진수 -> 3진수로 바꾸면서 "동시에 뒤집기"
    // 3으로 나눈 나머지를 result의 '뒤'에 차곡차곡 붙이면 
    // 수학적으로 알아서 순서가 뒤집힌 3진수 문자열이 완성됩니다!
    while (n > 0) {
        str_num += to_string(n % 3); 
        n /= 3;
    }
    
    // 2. 뒤집힌 3진수 문자열을 다시 10진수로 바꾸기
    int answer = 0;
    long long dec = 1; // 자릿값 (1, 3, 9, 27...)
    
    // 뒤에서부터 한 글자씩 빼서 계산합니다.
    for (int i = str_num.length() - 1; i >= 0; i--) {
        int digit = str_num[i] - '0'; // 문자를 숫자로 바꾸는 기법 ('1' -> 1)
        answer += digit * dec;
        dec *= 3;
    }
    
    return answer;
}