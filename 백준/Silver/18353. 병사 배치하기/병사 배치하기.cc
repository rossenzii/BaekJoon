#include <bits/stdc++.h>
using namespace std;

vector<int> vt;
vector<int> dp;
int cnt = 0;

int calculate(vector<int> arr) {
    for(int i=0;i<arr.size();i++){
        dp[i] = 1;

        for(int j=0;j<i;j++){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        cnt = max(cnt, dp[i]);
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;

    vt.resize(n);
    dp.resize(n);

    for(int i=0;i<n;i++) cin >> vt[i];
    int lds = calculate(vt);
    cout << n - lds;
}