#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

// 럭키 스트레이트
int main(){
  int digits[20];
  int len=0;
  int n; cin>>n;
  while(n>0){
    digits[len++]=n%10;
    n/=10;
  }
  int left_sum=0, right_sum=0;
  int mid=len/2;
  for(int i=0; i<mid; i++){
    right_sum+=digits[i];
    left_sum+=digits[len-1-i];
  }
  if(left_sum==right_sum) cout<<"LUCKY\n";
  else cout<<"READY\n";
  return 0;
}