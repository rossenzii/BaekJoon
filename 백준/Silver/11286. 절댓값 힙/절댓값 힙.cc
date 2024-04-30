#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Cmp{
    bool operator() (int a, int b){
        if (abs(a) != abs(b)) return abs(a)>abs(b);
        return a>b;
    }
};
int main() {
	fastio;
	priority_queue<int, vector<int>, Cmp> PQ;
	int n; cin >> n;
	while (n--) {
		int t; cin >> t;
		if (t) PQ.push(t);
		else {
			if (PQ.empty()) cout << 0 << '\n';
			else cout << PQ.top() << '\n', PQ.pop();
		}
	}
}