#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int start,cnt,answer;
int arr[3000001];
unordered_map<int, int> m;

int main(){
    fastio;
    int n,d,k,c; //접시수, 가짓수, 연속접시수, 쿠폰번호
    cin>>n>>d>>k>>c;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<k-1; i++){
        m[arr[i]]++; //sliding-window 초기 설정
    }
    
    int fin=k-1;
    for(int i=0; i<n; i++){
        int del = arr[start]; //나갈 접시 번호
        int cur = arr[fin%n]; //새로 들어올 접시 번호
        m[cur]++; //새 접시 윈도우에 포함
        int num=m.size();
        if(m.find(c)==m.end()){
            answer=max(answer, num+1);
        }
        else{
            answer = max(answer, num);
        }
        m[del]--;
        if(m[del]==0)
            m.erase(m.find(del));
        start++;
        fin++;
    }
    cout<<answer;
}
