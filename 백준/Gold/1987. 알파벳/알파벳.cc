#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char a[20][20];
bool visited[26];
int best = 0;

void backtrack(int x, int y, int cnt) {
    best = max(best, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

        int idx = a[nx][ny] - 'A';
        if (visited[idx]) continue;

        visited[idx] = true;
        backtrack(nx, ny, cnt + 1);
        visited[idx] = false;
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    visited[a[0][0] - 'A'] = true;
    backtrack(0, 0, 1);

    cout << best << "\n";
    return 0;
}