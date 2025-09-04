#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int K, M, P;
		cin >> K >> M >> P;
		
		int inhole[1002] = { 0, };
		vector<int> V[1002];
		priority_queue<int> pq[1002];

		for (int i = 0; i < P; i++) {
			int a, b;
			cin >> a >> b;
			V[a].push_back(b);
			inhole[b]++;
		}

		queue<pair<int,int>> Q;
		for (int i = 1; i <= M; i++) {
			if (inhole[i] == 0) Q.push({i,1});
		}

		while (!Q.empty()) {
			int str = Q.front().first;
			int step = Q.front().second;
			Q.pop();

			if (str == M) {
				cout << K << " " << step << "\n";
				break;
			}

			for (int i = 0; i < V[str].size(); i++) {
				int idx = V[str][i];
				inhole[idx]--;
				pq[idx].push(step);
				if (inhole[idx] == 0) {
					step = pq[idx].top();
					pq[idx].pop();
					if (!pq[idx].empty() && step == pq[idx].top()) {
						step++;
					}
					Q.push({ idx,step });
				}
			}
		}
	}
}