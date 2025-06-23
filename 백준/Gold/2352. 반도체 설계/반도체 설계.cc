#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#define MAX 40001

int n;
int arr[MAX];
vector<int> v;

int main() {
    fastio;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        if (v.empty() || v.back() < arr[i]) v.push_back(arr[i]);
        else {
            int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[pos] = arr[i];
        }
    }

    cout << v.size() << '\n';
    return 0;
}
