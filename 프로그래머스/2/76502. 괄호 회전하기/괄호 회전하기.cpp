#include <string>
#include <vector>
#include <unordered_map>
#include <stack> 
using namespace std;

int checkCorrectness(string s){
    stack<char> buk;
    unordered_map<char, char> pairs={
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    int sSize=s.size();
    for(int i=0; i<sSize; i++){
        char current=s[i];
        if(pairs.count(current)){ // ), ], } 중 하나인지 검사
            if(buk.empty()) return 0;
            if(buk.top()==pairs[current]){
                buk.pop();
            }else{
                return 0;
            }
        }else{
            buk.push(current);
        }
    }
    return buk.empty()?1:0;
}

int solution(string s) {
    int answer = 0;
    int sSize = s.size();
    string extendedS = s + s; 
    
    for(int i = 0; i < sSize; i++) {
        string rotated = extendedS.substr(i, sSize); 
        answer += checkCorrectness(rotated);
    }
    
    return answer;
}