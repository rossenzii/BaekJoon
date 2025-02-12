#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;
struct cmp{
    bool operator()(int a, int b){
        return a>b;
    }
};


int N, M, K;
vector<pair<int,int>> beers;

int main(){
    fastio;
    cin>> N>> M>> K;
    for(int i=0; i<K; i++){
        int p, l;
        cin >>p>>l;
        beers.push_back({p,l});
    }
    sort(beers.begin(), beers.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool{
        return p1.second < p2.second;});
    priority_queue<int, vector<int>, cmp> pq; //오름차순
    ll total=0;
    for(auto beer: beers){
        pq.push(beer.first);
        total +=beer.first;
        
        if(pq.size()>N){
            total -= pq.top(); //작은 선호도의 술은 뺀다
            pq.pop();
        }
        if(pq.size()==N && total>=M){
            cout<<beer.second<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;
}