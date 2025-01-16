#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
typedef long long ll;
using namespace std;

// 이분 탐색
int main(){
    fastio;
    int n,m; cin>>n>>m;
    vector<int> v(n);
    int low, high;
    low=1; high=0;
    
    for(int i=0; i<n; i++){
        cin>>v[i];
        high+=v[i];
    }
    
    int mid;
    int total; // 녹화중인 blue 남은 공간
    int result = 0;
    
    while(low<=high){
        mid = (low + high)/2;
        total = mid; //초기 blue 공간
        int cnt =1 ; //blue 1개로 시작
        bool possible = true;
        
        for(int i=0; i<n; i++){
            if(mid<v[i]){ // blue의 크기가 강의보다 작으면 성립 x
                possible = false;
                break;
            }
            if(total < v[i]){// 남은 공간이 다음 강의를 담지 못함
                total = mid; //다음 blue 사용
                cnt++;
            }
            total -= v[i]; //공간 차감
        }
        if(cnt > m || !possible){
            low = mid+1; // blue 크기 늘리기
        }else if(cnt<=m){
            high = mid-1; //blue 크기 작게
            result = mid; //크기 저장
        }
    }
    cout<<result<<endl;
    return 0;

}