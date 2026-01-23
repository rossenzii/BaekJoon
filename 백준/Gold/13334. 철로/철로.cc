#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int d,n;
int answer=0;
vector<pair<int,int>>v;
priority_queue<int> pq; // pq.top():가장 큰 값

bool cmp(pair<int, int> a, pair<int, int> b){
  // second 기준 오름차순, second가 같으면 first 기준 오름차순
  if(a.second == b.second) return a.first<b.first;
  return a.second<b.second;
}

int main(){
  cin>>n;
  int f,s;
  for(int i=0; i<n; i++){
    cin>>f>>s;
    if(f<s) v.push_back({f,s});
    else v.push_back({s,f});
  }
  cin>>d;
  sort(v.begin(), v.end(), cmp);
  for(int i=0; i<v.size(); i++){
    int start=v[i].first;
    int end=v[i].second;
    if(end-start<=d) pq.push(-start); // 길이 d를 넘는 선분은 제외
    else continue;

    while(!pq.empty()){
      if(-pq.top()<end-d) pq.pop(); // end-d: 왼쪽 끝, -pq.top(): pq 안에서 가장 왼쪽, 가장 작은 start
      else{
        answer = max(answer, (int)pq.size()); 
        break;
      }
    }
  }
  cout<<answer;

}