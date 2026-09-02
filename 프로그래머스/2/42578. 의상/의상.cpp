#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hashCnt;  // 함수 안으로 옮기는 걸 추천!
    
    for (int i = 0; i < clothes.size(); i++) {
        hashCnt[clothes[i][1]]++;
    }
    
    long long answer = 1;
    for (auto& [category, count] : hashCnt) {
        answer *= (count + 1);
    }
    
    return answer - 1;
}