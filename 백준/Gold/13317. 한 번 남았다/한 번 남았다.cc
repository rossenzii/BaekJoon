#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << 50 << ' ' << 49 << '\n';
	for (int i = 49; i > 0; i--) cout << i << ' ' << i + 1 << ' ' << -1 << '\n';
}