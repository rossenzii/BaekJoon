#include <string>
#include <vector>

using namespace std;



vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long x:numbers){
        if(x%2==0){ // 짝수면 무조건 +1
            answer.push_back(x+1);
        }else{
            // 홀수면 가장 오른쪽 0찾기
            long long bit=1;
            while((x&bit)){
                bit<<=1; // 0001, 0010 이동
            }
            answer.push_back(x+(bit>>1)); // 1000이 0100됨
        }
    }
    return answer;
}