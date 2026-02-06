#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main(){
  string s; cin>>s;
  int cnt=0;
  char now=s[0];
  for(int i=1; i<s.length(); i++){
    if(now!=s[i]){
      cnt++;
      now=s[i];
    }
  }
  if(cnt%2==1){ // 홀수
    cnt/=2;
    cnt++;
  }
  else{
    cnt/=2;
  }
  cout<<cnt;
  return 0;
}