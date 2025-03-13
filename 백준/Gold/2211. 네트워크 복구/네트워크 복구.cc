#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define INF 1e9
using namespace std;

int N, M;
vector<pair<int, int>> v[1001];  // 인접 리스트 (최대 1000개 노드)
vector<int> d;  // 최단 거리 저장
vector<int> parent;  // 복구해야 할 경로 저장

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;  // 이미 최단 경로가 설정됨

        for (auto edge : v[now]) {
            int next = edge.first;
            int cost = edge.second;

            if (d[next] > d[now] + cost) {
                d[next] = d[now] + cost;
                pq.push({d[next], next});
                parent[next] = now;  // 최단 경로 갱신 시, 어디서 왔는지 기록
            }
        }
    }
}

int main() {
    fastio;
    cin >> N >> M;
    
    d.resize(N + 1, INF);
    parent.resize(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});  // 양방향 연결
    }

    dijkstra(1);  // 1번 노드에서 시작

    vector<pair<int, int>> result;
    for (int i = 2; i <= N; i++) {  // 1번을 제외하고 연결된 경로 출력
        if (parent[i] != -1) {
            result.push_back({parent[i], i});
        }
    }

    cout << result.size() << '\n';
    for (auto edge : result) {
        cout << edge.first << " " << edge.second << '\n';
    }

    return 0;
}
