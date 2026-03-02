#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct cmp{
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
		return a.first > b.first; // 숫자 작은 구역이 먼저 확장
	}
};

int N, K, box[200][200], S, X, Y;
pair<int, int> dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

int main(){

	cin >> N >> K;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> box[i][j];
			if (box[i][j] != 0){
				pq.push(make_pair(box[i][j], make_pair(i, j))); // (x,y) 저장해서 시작점 생성
			}
		}
	}

	cin >> S >> X >> Y;
	
	for (int i = 0; i < S; i++){ 
		// 새로 확장된 칸을 담을 큐
		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> cpq; 


		while (!pq.empty()){
			int n = pq.top().first, cy = pq.top().second.first, cx = pq.top().second.second;
			pq.pop();

			for (int k = 0; k < 4; k++){
				int ny = cy + dir[k].first, nx = cx + dir[k].second;

				if (ny < 0 || ny >= N || nx < 0 || nx >= N || box[ny][nx] != 0)
					continue;

				box[ny][nx] = n; // 빈칸을 현재 구역으로 채우기, n: 현재 구역 번호 ex) 1, 2, 3
				cpq.push(make_pair(n, make_pair(ny, nx)));
			}
		}

		pq = cpq;
	}

	cout << box[X-1][Y-1];

	return 0;
}