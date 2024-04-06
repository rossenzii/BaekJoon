#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

queue<int> Q[21]; 

int main() {
	fastio;
	int n, k; cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int len = s.size();
		while (Q[len].size() && Q[len].front() < i - k) Q[len].pop();
		ans += Q[len].size(); Q[len].push(i);
	}
	cout << ans << '\n';
}