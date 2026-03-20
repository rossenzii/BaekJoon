#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
extern int excavate(int);

// dp[l][r] = 범위 [l, r]에서 100% 보물을 찾기 위한 최소 비용
// 그리고 그때 첫 번째로 파야 할 열
int dp[201][201];
int best[201][201]; // 각 범위에서 첫 번째로 파야 할 열

void buildDP(vector<int>& depth, int w) {
    // 범위 길이 1일 때: 그 열을 파면 됨
    for (int i = 1; i <= w; i++) {
        dp[i][i] = depth[i - 1];
        best[i][i] = i;
    }

    // 범위 길이 2 이상
    for (int len = 2; len <= w; len++) {
        for (int l = 1; l + len - 1 <= w; l++) {
            int r = l + len - 1;
            dp[l][r] = INT_MAX;

            for (int mid = l; mid <= r; mid++) {
                // mid를 팠을 때 최악의 경우 비용
                // 왼쪽 [l, mid-1]과 오른쪽 [mid+1, r] 중 더 큰 쪽
                int leftCost  = (mid > l) ? dp[l][mid - 1] : 0;
                int rightCost = (mid < r) ? dp[mid + 1][r] : 0;
                int cost = depth[mid - 1] + max(leftCost, rightCost);

                if (cost < dp[l][r]) {
                    dp[l][r] = cost;
                    best[l][r] = mid;
                }
            }
        }
    }
}

int solution(vector<int> depth, int money) {
    int w = depth.size();
    buildDP(depth, w);

    int left = 1, right = w;

    while (true) {
        int col = best[left][right];
        int result = excavate(col);

        if (result == 0) return col;
        else if (result == -1) right = col - 1; // 보물이 왼쪽
        else left = col + 1;                     // 보물이 오른쪽
    }
}