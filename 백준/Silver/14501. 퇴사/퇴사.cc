#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int arr[16][2];   // 상담 기간, 수익
int dp[16];       // dp[i] = i일까지 얻을 수 있는 최대 수익

int main(){
    fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 0; i < n; i++){
        // 상담을 하는 경우
        if(i + arr[i][0] <= n){
            dp[i + arr[i][0]] = max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
        }
        //상담을 안 하는 경우
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n];
}