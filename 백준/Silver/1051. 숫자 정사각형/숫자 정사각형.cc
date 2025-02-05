#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int result=1;
int arr[51][51]={0};
string input;

int main(){
    int N,M; cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>input;
        for(int j=0; j<input.size(); j++)
            arr[i][j]=input[j]-'0';
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int cnt=0;
            for(int k=1; ;k++){
                if((j+k)>=M || (i+k)>=N) break;
                if(arr[i][j]==arr[i][j+k] && arr[i][j]==arr[i+k][j] && arr[i][j]==arr[i+k][j+k])
                    if(cnt<k)
                        cnt=k;
            }
            if((cnt+1)>result) result = cnt+1;
        }
    }
    cout<<result*result<<'\n';
}