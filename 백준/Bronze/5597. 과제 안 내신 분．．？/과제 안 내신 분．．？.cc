#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    int n;
    int arr[31]={0,}; //0~30번까지 방이 있음
    for(int i=0; i<28; i++){ //28번 입력받음
        cin>>n;
        arr[n]=1;
    }
    for(int i=1; i<=30; i++){ //횟수 반복
        if(!arr[i]) cout<<i<<'\n';
    }
}