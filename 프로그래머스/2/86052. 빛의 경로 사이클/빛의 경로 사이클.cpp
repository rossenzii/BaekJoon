#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dr[]={-1,0,1,0}; //상,우,하,좌 (시계방향)
int dc[]={0,1,0,-1};
bool visited[500][500][4]; // 이미 빛이 지나갔는지 체크, 현재위치+빛의방향


vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int R=grid.size(); // 격자 행 가로
    int C=grid[0].size(); // 격자 열 세로
    
    for(int r=0; r<R; ++r){
        for(int c=0; c<C; ++c){
            for(int d=0; d<4; d++){
                if(visited[r][c][d]) continue;
                int cnt=0; // cycle 길이
                int cr=r, cc=c, cd=d; // 현재 위치와 방향
                while(!visited[cr][cc][cd]){
                    visited[cr][cc][cd]=true;
                    cnt++;
                    // 다음 위치로 이동
                    cr=(cr+dr[cd]+R)%R; // 0+(-1)을 나눌 수 없으니 R 더하기
                    cc=(cc+dc[cd]+C)%C;
                    if(grid[cr][cc]=='L'){
                        cd=(cd+3)%4;
                    }else if(grid[cr][cc]=='R'){
                        cd=(cd+1)%4;
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}