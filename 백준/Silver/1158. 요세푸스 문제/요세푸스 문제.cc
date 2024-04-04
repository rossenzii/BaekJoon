#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> Sol(int n, int k) {
	vector<int> ret; queue<int> Q;
	for (int i = 1; i <= n; i++) Q.push(i);
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i < k; i++) {
			Q.push(Q.front()); Q.pop();
		}
		ret.push_back(Q.front()); Q.pop();
	}
	return ret;
}

void Print(const vector<int>& v) {
	cout << '<';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << '>' << '\n';
}

int main() {
	fastio;
	int n, k; cin >> n >> k;
	auto v = Sol(n, k); Print(v);
}