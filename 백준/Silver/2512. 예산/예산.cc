#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);


int calculate(int n, int m, vector<int> &budget){
  int start=0;
  int end=budget[n-1]; //가능한 상한액의 최댓값
  int result, sum;
  while(start<=end){
    sum=0;
    int mid=(start+end)/2;
    for(int i=0; i<n; i++){
      sum+=min(budget[i], mid);
    }
    if(m>=sum){
      result=mid;
      start=mid+1;
    }else{
      end=mid-1;
    }
  }
  return result;
}


int main(){
  fastio;
  vector<int> budget;
  int n; cin>>n;
  for(int i=0; i<n; i++){
    int x; cin>>x;
    budget.push_back(x);
  }
  sort(budget.begin(), budget.end());
  int m; cin>>m;
  cout<< calculate(n, m, budget);
}