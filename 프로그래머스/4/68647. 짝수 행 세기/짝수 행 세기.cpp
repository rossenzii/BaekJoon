#include <string>
#include <vector>

using namespace std;

const int MODULA = 10000019;

int solution(vector<vector<int>> a) {
    int row_size = a.size();    
    int col_size = a[0].size(); 
    
    // 각 열의 1의 개수 구하기
    vector<int> yNum(col_size, 0);
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col_size; j++){
            if(a[i][j] == 1){
                yNum[j]++;
            }
        }
    }
    
    // 1. nCr 테이블 채우기
    vector<vector<long long>> nCr(row_size + 1, vector<long long>(row_size + 1, 0));
    for(int i = 0; i <= row_size; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) nCr[i][j] = 1;
            else{
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MODULA;
            }
        }
    }
    
    // 2. dp 테이블 선언 (vector로 안전하게 0 초기화)
    vector<vector<long long>> dp(col_size + 1, vector<long long>(row_size + 1, 0));
    
    // 시작점: 0번째 열일 때 모든 행이 짝수인 경우 1가지
    dp[0][row_size] = 1;
    
    for(int i = 1; i <= col_size; i++){
        int k = yNum[i-1];
        
        // ✨ [예외 처리] 이번 열에 배치할 1이 하나도 없다면?
        // 어제 상태가 그대로 오늘 상태가 됩니다. (물건을 안 넣었으니 상태 변화 없음)
        if (k == 0) {
            for(int j = 0; j <= row_size; j++) {
                dp[i][j] = dp[i-1][j];
            }
            continue; // 다음 열로 바로 넘어갑니다.
        }
        
        for(int j = 0; j <= row_size; j++){ 
            if(dp[i-1][j] == 0) continue; 
            
            for(int num_x = 0; num_x <= k; num_x++){
                int target_odd = k - num_x;             
                int current_odd = row_size - j;         
                
                if(target_odd < 0 || target_odd > current_odd) continue;
                if(num_x > j) continue;
                
                int next_j = j - num_x + target_odd; 
                
                long long cases = (dp[i-1][j] * nCr[j][num_x]) % MODULA;
                cases = (cases * nCr[current_odd][target_odd]) % MODULA;
                
                dp[i][next_j] = (dp[i][next_j] + cases) % MODULA;
            }
        }
    }
    
    // 최종 모든 열을 돌고, 모든 행이 짝수가 된 경우의 수 반환
    int answer = dp[col_size][row_size];
    return answer;
}