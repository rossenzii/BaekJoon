#include <string>
#include <vector>
using namespace std;

int getCol(int idx, int w) {
    int col = idx % w;
    if((idx / w) % 2 == 1) col = w - 1 - col;
    return col;
}

int solution(int n, int w, int num) {
    int target_row = (num - 1) / w;
    int target_col = getCol(num - 1, w);
    
    int last_row = (n - 1) / w;
    int last_col = getCol(n - 1, w);
    
    int answer = last_row - target_row;
    if((last_row % 2 == 0 && target_col <= last_col) || 
       (last_row % 2 == 1 && target_col >= last_col)) {
        answer++;
    }
    
    return answer;
}