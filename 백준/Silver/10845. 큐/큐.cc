#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    queue<int> Q;
    int N,t;
    cin>>N; //문자열 1개만 입력받으니 cin.ignore() 쓰지 않아도 됨
    while(N--){
        string s;
        cin>>s;
        if(s=="push"){
            cin>>t; Q.push(t);
        }
        else if (s=="pop"){
            cout<<(Q.empty()? -1:Q.front())<<'\n';
            (Q.size()?Q.pop():void()); //size를 확인해서 0이 아닐때만 pop
        }
        else if (s=="size"){
            cout<<Q.size()<<'\n';
        }
        else if (s=="empty"){
            cout<<(Q.empty()? 1:0)<<'\n';
        }
        else if (s=="front"){
            cout<<(Q.empty()? -1: Q.front())<<'\n';
        }
        else if (s=="back"){
            cout<<(Q.empty()? -1: Q.back())<<'\n';
        }
    }
}