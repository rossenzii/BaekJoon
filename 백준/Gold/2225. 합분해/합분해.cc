#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;
const ll m = 1000000000;

int dp[210][210];
int main(){
    int N, K; cin>>N>>K;
    for (int i=1; i<=N; i++){
        dp[i][1]=1;
    }
    for(int i=1; i<=K; i++){
        dp[1][i]=i;
    }
    for(int i=2; i<=N; i++){
        for(int j=2; j<=K; j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%m;
        }
    }
    cout<<dp[N][K]<<'\n';
    return 0;
}