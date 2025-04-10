#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define long long size_t
using namespace std;

int N;
int arr[1000];

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    
    int res = 1;
    for(int i=0; i<N; i++){
        if(arr[i]>res){
            break;
        }
        res+=arr[i];
    }
    cout<<res;
}