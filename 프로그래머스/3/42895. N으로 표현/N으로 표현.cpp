#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int cal(int n, int number){
    vector<unordered_set<int>> dp(9); // n을 i개 써서 만드는 수들의 집합
    
    // n, nn, nnn... 형태로 이어붙인 수 초기화
    int base_num = 0;
    for(int i = 1; i <= 8; i++){
        base_num = base_num * 10 + n;
        dp[i].insert(base_num);
    }
    
    for(int i = 1; i <= 8; i++){
        // j: 첫번째 피연산자의 n 사용횟수, (i-j): 두번째 피 연산자의 n 사용횟수
        for(int j = 1; j < i; j++){
            for(int op1 : dp[j]){
                for(int op2 : dp[i - j]){
                    dp[i].insert(op1 + op2);
                    dp[i].insert(op1 - op2);
                    dp[i].insert(op1 * op2);
                    
                    if(op2 != 0){
                        dp[i].insert(op1 / op2);
                    }
                }
            }
        }
        if(dp[i].count(number)){
            return i;
        }
    }
    return -1;
}

int solution(int N, int number) {
    // N과 number가 같을 때의 예외 처리를 cal 함수 안에서 처리하므로 바로 대입
    int answer = cal(N, number);
    return answer;
}