#include <iostream>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;


int main(){
  int t; cin >> t;
  while(t--){
    int n; cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
      cin>>coins[i];
    }
    int m; cin>>m;
    vector<int> dp(m+1, 0); // 0으로 초기화
    dp[0]=1;
    for(int coin : coins){
      for(int k=coin; k<=m; k++){
        dp[k] +=dp[k-coin];
      }
    }
    cout<<dp[m]<<endl;
  }
  return 0;
}