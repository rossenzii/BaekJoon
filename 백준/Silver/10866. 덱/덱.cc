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
    int N,T;
    cin>>N;
    deque<int> DQ;
    while(N--){
        string s; cin>>s;
        int F;
        if(s=="push_front") {cin>>T; DQ.push_front(T);}
        else if (s=="push_back"){cin>>T; DQ.push_back(T);}
        else if(s=="pop_front") {
            if(DQ.empty()) cout<<"-1"<< '\n';
            else{
                F=DQ.front(); DQ.pop_front(); cout<<F<< '\n';} }
        else if(s=="pop_back"){
            if(DQ.empty()) cout<<"-1"<< '\n';
            else{
                F=DQ.back(); DQ.pop_back(); cout<<F<< '\n';}
        }
        else if(s=="size"){
            cout<<DQ.size()<< '\n';
        }
        else if(s=="empty"){
            cout<<(DQ.empty()? 1:0)<< '\n';
        }
        else if(s=="front"){
            cout<<(DQ.empty()?-1:DQ.front())<< '\n';
        }
        else if(s=="back"){
            cout<<(DQ.empty()?-1:DQ.back())<< '\n';
        }
            
    }
}
