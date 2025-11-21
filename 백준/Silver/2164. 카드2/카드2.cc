#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        q.pop();                // 맨 위 버리고
        q.push(q.front());      // 다음 카드 맨 뒤로 보내고
        q.pop();
    }

    cout << q.front();
}