#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
    int x;
    int y;
};

Point store[100];
Point festival;
Point home;
bool visited[100];

int distManhattan(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool BFS(int n) {
    queue<Point> q;
    q.push(home);

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        // 현재 위치에서 페스티벌까지 갈 수 있으면 성공
        if (distManhattan(cur, festival) <= 1000) return true;

        // 편의점들 탐색
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            if (distManhattan(cur, store[i]) <= 1000) {
                visited[i] = true;
                q.push(store[i]);
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cin >> home.x >> home.y;

        for (int i = 0; i < n; i++) {
            cin >> store[i].x >> store[i].y;
        }

        cin >> festival.x >> festival.y;

        memset(visited, 0, sizeof(visited));

        cout << (BFS(n) ? "happy\n" : "sad\n");
    }

    return 0;
}