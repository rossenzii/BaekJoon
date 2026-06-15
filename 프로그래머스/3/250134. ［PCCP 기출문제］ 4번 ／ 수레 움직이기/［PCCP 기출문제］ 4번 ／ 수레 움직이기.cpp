#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 💡 전역 변수로 선언하여 모든 함수에서 쉽게 접근하도록 만듭니다.
int hSize, vSize;
int answer = 999999; // 최솟값을 찾기 위해 아주 큰 값으로 초기화
vector<vector<int>> map;

// 2차원 방문 체크 판
vector<vector<bool>> rVisited;
vector<vector<bool>> bVisited;

// 상하좌우 이동 방향 (북, 남, 서, 동)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 🔍 질문하신 '이동 가능합니까'를 담당하는 판정 함수입니다!
bool canMove(int r_nx, int r_ny, int b_nx, int b_ny, pair<int,int> rCur, pair<int,int> bCur, bool rArrived, bool bArrived) {
    
    // 1. 범위 검사 (격자판을 벗어나면 안 됨)
    if (r_nx < 0 || r_nx >= hSize || r_ny < 0 || r_ny >= vSize) return false;
    if (b_nx < 0 || b_nx >= hSize || b_ny < 0 || b_ny >= vSize) return false;
    
    // 2. 벽 검사 (벽인 '5'로는 갈 수 없음)
    if (map[r_nx][r_ny] == 5 || map[b_nx][b_ny] == 5) return false;
    
    // 3. 내 방문 기록 검사 (이미 갔던 곳은 다시 갈 수 없음, 단 도착한 수레는 예외)
    if (!rArrived && rVisited[r_nx][r_ny]) return false;
    if (!bArrived && bVisited[b_nx][b_ny]) return false;
    
    // 4. 동시 충돌 검사 (두 수레가 같은 칸으로 동시에 들어갈 수 없음)
    if (r_nx == b_nx && r_ny == b_ny) return false;
    
    // 5. 엇갈림 충돌 검사 (빨간 수레가 파란 현재 자리로 가고, 파란 수레가 빨간 현재 자리로 가면 X)
    if (r_nx == bCur.first && r_ny == bCur.second && b_nx == rCur.first && b_ny == rCur.second) return false;
    
    // 모든 유효성 검사를 통과하면 비로소 이동 허가!
    return true;
}

// 🔄 DFS 백트래킹 탐색 함수
void solve(pair<int,int> rCur, pair<int,int> bCur, int count) {
    // [기저 조건 1] 빨간 수레가 '3'(도착지)에 도달하고, 파란 수레가 '4'(도착지)에 동시에 도달했다면 종료!
    if (map[rCur.first][rCur.second] == 3 && map[bCur.first][bCur.second] == 4) {
        answer = min(answer, count);
        return;
    }
    
    // [기저 조건 2] 가지치기: 이미 찾은 최솟값보다 더 많이 움직였다면 더 볼 필요 없음
    if (count >= answer) return;
    
    // 각 수레가 이미 도착지에 도달했는지 확인 (도착했다면 고정되어 움직이지 않음)
    bool rArrived = (map[rCur.first][rCur.second] == 3);
    bool bArrived = (map[bCur.first][bCur.second] == 4);
    
    // 빨간 수레 4방향 탐색
    for (int rd = 0; rd < 4; rd++) {
        int r_nx = rArrived ? rCur.first : rCur.first + dx[rd];
        int r_ny = rArrived ? rCur.second : rCur.second + dy[rd];
        
        // 파란 수레 4방향 탐색
        for (int bd = 0; bd < 4; bd++) {
            int b_nx = bArrived ? bCur.first : bCur.first + dx[bd];
            int b_ny = bArrived ? bCur.second : bCur.second + dy[bd];
            
            // 💡 위에서 만든 판정 함수를 호출해서 안전한지 확인합니다!
            if (canMove(r_nx, r_ny, b_nx, b_ny, rCur, bCur, rArrived, bArrived)) {
                
                // ① 다음 갈 곳 방문 도장 찍기 (아직 도착 안 한 수레만 찍음)
                if (!rArrived) rVisited[r_nx][r_ny] = true;
                if (!bArrived) bVisited[b_nx][b_ny] = true;
                
                // ② 한 걸음 전진하여 재귀 호출
                solve({r_nx, r_ny}, {b_nx, b_ny}, count + 1);
                
                // ③ 🔥 중요: 다른 경로 탐색을 위해 잉크 지우기 (백트래킹)
                if (!rArrived) rVisited[r_nx][r_ny] = false;
                if (!bArrived) bVisited[b_nx][b_ny] = false;
            }
        }
        // 빨간 수레가 이미 고정되었다면 4방향을 다 돌 필요가 없으므로 첫 바퀴(파란 수레 탐색) 후 탈출
        if (rArrived) break;
    }
}

int moveCart(pair<int,int> red, pair<int,int> blue) {
    // 방문 체크 판 초기화
    rVisited.assign(hSize, vector<bool>(vSize, false));
    bVisited.assign(hSize, vector<bool>(vSize, false));
    
    // 수레들의 최초 시작점도 방문한 것으로 간주하여 찍고 시작합니다.
    rVisited[red.first][red.second] = true;
    bVisited[blue.first][blue.second] = true;
    
    // DFS 시작! (이동 카운트 0)
    solve(red, blue, 0);
    
    // 만약 탐색이 끝났는데도 answer가 초기값 그대로라면 도달할 수 없는 미로이므로 0 반환
    if (answer == 999999) return 0;
    return answer;
}

int solution(vector<vector<int>> maze) {
    map = maze; // 전역 map에 복사
    hSize = maze.size();
    vSize = maze[0].size();
    
    pair<int,int> redStart;
    pair<int,int> blueStart;
    
    // 시작 위치 탐색
    for (int i = 0; i < hSize; i++) {
        for (int j = 0; j < vSize; j++) {
            if (maze[i][j] == 1) redStart = {i, j};
            else if (maze[i][j] == 2) blueStart = {i, j};
        }
    }
    
    return moveCart(redStart, blueStart);
}