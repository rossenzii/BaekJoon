#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    int T;
    cin >> T; // 테스트 케이스 

    while (T--) {
        int N1, N2;
        // 수첩 1 
        cin >> N1;
        vector<int> v1(N1);
        for (int i = 0; i < N1; i++) {
            cin >> v1[i];
        }
        sort(v1.begin(), v1.end());

        // 수첩 2 
        cin >> N2;
        for (int i = 0; i < N2; i++) {
            int b;
            cin >> b;
            if (binary_search(v1.begin(), v1.end(), b)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}
