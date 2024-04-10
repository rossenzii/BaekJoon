#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    int n,t,ans=0;
    cin>>n>>t;
    deque<int> DQ;
    for(int i=1; i<=n; i++){
        DQ.push_back(i);
    }
    while(t--){
        int idx=0, a;
        cin>>a;
        for(int i=0; i<DQ.size(); i++){
            if(DQ.front()==a) {idx= i; break;} //idx는 a가 처음으로 나오는 위치임
            DQ.push_back(DQ.front()); DQ.pop_front();
        }
        ans +=min<int>(idx,DQ.size() - idx); //<int>는 min이 사용할 자료형을 뜻함
        DQ.pop_front();
    }
    cout<<ans<<'\n';
}