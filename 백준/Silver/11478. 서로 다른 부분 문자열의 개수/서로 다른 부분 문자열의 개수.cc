#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int main(){
    fastio;
    string str;
    cin>>str;
    set <string> S;
    int count=0;
    for (int i=0; i<str.size(); i++) // 모든 시작 가능한 위치
        for(int j=1; j<=str.size()-i; j++) // 만들어질 수 있는 문자열 길이 case
            S.insert(str.substr(i,j)); //i=자르기 시작하는 위치, j=추출할 문자열 갯수
    cout<<S.size()<<'\n';
}