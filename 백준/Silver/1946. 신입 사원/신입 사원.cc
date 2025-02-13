#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int T, N, ret;
vector <pair<int, int>> score;

int main(){
    fastio;
    cin>>T;
    while(T--){
        cin>>N;
        score.clear(); //여러 번 반복하므로 초기화 필요
        for(int i=0; i<N; i++){
            int s, w;
            cin >> s>> w;
            score.push_back({s,w});
        }
        sort(score.begin(), score.end());
        
        int tmp=0; //기준
        ret=1;
        for(int i=0; i<N; i++){
            if(score[tmp].second > score[i].second){
                ret++;
                tmp=i; //현재 선택한 인덱스
            }
        }
        cout<<ret<<'\n';
    }
    return 0;
}
