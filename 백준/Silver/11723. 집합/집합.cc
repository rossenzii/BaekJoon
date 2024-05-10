#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	bitset<21> BIT;
	int q; cin >> q;
	while (q--) {
		string s; int x; cin >> s;
		if (s == "add") cin >> x, BIT[x] = 1;
		else if (s == "remove") cin >> x, BIT[x] = 0;
		else if (s == "check") cin >> x, cout << BIT[x] << '\n';
		else if (s == "toggle") cin >> x, BIT[x].flip();
		else if (s == "all") BIT.set();
		else BIT.reset();
	}
}
