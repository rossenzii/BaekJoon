#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    int dp[10001];
    memset(dp, 0, sizeof(dp));

    while(n--){
        int time, score;
        cin >> time >> score;

        for(int j = t; j >= time; j--){
            dp[j] = max(dp[j], dp[j - time] + score);
        }
    }

    cout << dp[t] << "\n";
    return 0;
}