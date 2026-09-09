#include <string>
#include <vector>

using namespace std;

string calc(string number, int k){
    vector<char> answer;
    for(int i=0; i<number.size(); i++){
        while(!answer.empty() && k>0 && number[i]>answer.back()){
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    if(k>0){
        answer.resize(answer.size()-k); // 이만큼으로 잘라버리기
    }
    return string(answer.begin(), answer.end());
}

string solution(string number, int k) {
    return calc(number, k);
}