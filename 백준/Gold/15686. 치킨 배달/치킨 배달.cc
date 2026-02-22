#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
int minCityDistance = INT_MAX;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> selected;

void calculateDistance() {
    int cityDistance = 0;
    for (int i = 0; i < (int)house.size(); i++) {
        int minHouseDistance = INT_MAX;
        for (int j = 0; j < (int)chicken.size(); j++) {
            if (selected[j] == 1) {
                int houseDistance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                minHouseDistance = min(minHouseDistance, houseDistance);
            }
        }
        cityDistance += minHouseDistance;
    }
    minCityDistance = min(minCityDistance, cityDistance);
}

void selectChicken() {
    //selected = {0,0,0,1,1} -> chicken이 5개, M=2 일때
    for (int i = 0; i < (int)chicken.size() - M; i++) { selected.push_back(0); }
    for (int i = 0; i < M; i++) { selected.push_back(1); }
    do {
        calculateDistance();
    } while (next_permutation(selected.begin(), selected.end())); // next_permutation은 다음 순열을 만들어주는 함수
}

int main() {
    cin >> N >> M;

    int flag;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> flag;
            if (flag == 1) { house.push_back({i, j}); }
            else if (flag == 2) { chicken.push_back({i, j}); }
        }
    }

    selectChicken();
    cout << minCityDistance << endl;

    return 0;
}
