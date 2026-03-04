#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 987654321
using namespace std;

int arr[110][110];

int main(){
    int n,m; cin>>n>>m;
    int a,b,c;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            arr[i][j]=INF;
        }
    for(int i=1; i<=n; i++){
        arr[i][i]=0;
    }
    for(int k=1; k<=m; k++){
        cin>>a>>b>>c;
        if(arr[a][b]>c)
            arr[a][b]=c;
    }
    
    for(int r=1; r<=n; r++)
        for(int p=1; p<=n; p++)
            for(int q=1; q<=n; q++){
                if(arr[p][q] > arr[p][r]+arr[r][q])
                    arr[p][q] = arr[p][r]+arr[r][q];
            }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j]==INF) cout<<'0'<<'\n';
            else cout<<arr[i][j]<<'\n';
        }
    }
    
}