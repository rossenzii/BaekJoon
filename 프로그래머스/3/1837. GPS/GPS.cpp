#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[210];
int dp[210][210];
const int inf = 987654321;

// 그래프와 DP 테이블 초기화
void init(vector<vector<int>> edge_list) {
    for (int i = 0; i < 210; i++) adj[i].clear();
    for (int i = 0; i < 210; i++)
        for (int j = 0; j < 210; j++)
            dp[i][j] = inf;

    for (auto &e : edge_list) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    init(edge_list);

    dp[0][gps_log[0]] = 0;

    // DP 수행
    for (int i = 1; i < k - 1; i++) {
        for (int j = 1; j <= n; j++) {
            int add = (gps_log[i] == j ? 0 : 1);

            // 같은 노드에 머무르는 경우
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + add);

            // 인접한 노드에서 오는 경우
            for (auto p : adj[j]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][p] + add);
            }
        }
    }

    // 도착지까지의 최소 수정 횟수 계산
    answer = inf;
    for (auto p : adj[gps_log.back()]) {
        answer = min(answer, dp[gps_log.size() - 2][p]);
    }

    if (answer > inf / 2)
        answer = -1;

    return answer;
}