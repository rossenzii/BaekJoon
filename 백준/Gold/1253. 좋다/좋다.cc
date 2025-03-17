#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio; // 빠른 입출력
    int N, count = 0;
    cin >> N;

    vector<int> col(N);
    for (int i = 0; i < N; i++) {
        cin >> col[i];
    }

    sort(col.begin(), col.end()); // 오름차순 정렬

    for (int i = 0; i < N; i++) {
        int val = col[i]; // 현재 확인할 값
        int l = 0, r = N - 1; // 투 포인터 초기화

        while (l < r) {
            if (l == i) { // 현재 확인 중인 값 i를 제외
                l++;
                continue;
            }
            if (r == i) { // 현재 확인 중인 값 i를 제외
                r--;
                continue;
            }

            int sum = col[l] + col[r];

            if (sum == val) { // 두 수의 합이 val과 같다면
                count++; 
                break; // 한 번 찾았으면 종료
            } 
            else if (sum < val) { // 합이 더 작다면 l 증가
                l++;
            } 
            else { // 합이 더 크다면 r 감소
                r--;
            }
        }
    }

    cout << count << '\n'; // 결과 출력
    return 0;
}
