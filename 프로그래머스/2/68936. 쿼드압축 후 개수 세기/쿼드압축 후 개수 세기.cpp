#include <string>
#include <vector>

using namespace std;

// 💡 4. solve 함수와 공유할 수 있도록 answer를 전역 변수로 빼고 {0, 0}으로 초기화합니다.
vector<int> answer = {0, 0}; 

// 💡 2. 함수 이름을 checkNum으로 통일
bool checkNum(int r, int c, int size, const vector<vector<int>>& arr){
    int first_val = arr[r][c];
    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            // 💡 1. arr[r][c] 대신 루프 변수인 arr[i][j]를 검사해야 합니다!
            if(arr[i][j] != first_val){ 
                return false;
            }
        }
    }
    return true;
}

void solve(int r, int c, int size, const vector<vector<int>>& arr){
    // 💡 2. 정의한 이름(checkNum)으로 올바르게 호출
    if(checkNum(r, c, size, arr)){
        // 💡 3. 중복된 answer[ ] 코드를 지우고 arr[r][c] 번 방의 카운트를 올립니다.
        answer[arr[r][c]]++;
        return;
    }
    int n_size = size / 2;
    solve(r, c, n_size, arr);
    solve(r, c + n_size, n_size, arr);
    solve(r + n_size, c, n_size, arr);
    solve(r + n_size, c + n_size, n_size, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    // 프로그래머스는 여러 테스트 케이스를 연속으로 돌리므로 
    // 전역 변수를 쓰기 전에 항상 {0, 0}으로 한 번 청소해 주는 것이 안전합니다.
    answer = {0, 0}; 
    
    solve(0, 0, arr.size(), arr);
    return answer;
}