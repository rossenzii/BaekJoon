#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> res;
vector<vector<int>> arr;
  int n,m,k;
string tmp; // 이어 붙여서 만들어질 문자열
int dx[]={0, 0, 1, -1, 1, -1, 1, -1};
int dy[]={1, -1, 0, 0, 1, 1, -1, -1 };

void dfs(int x, int y){
  if(tmp.length()>5) return;

  auto iter = res.find(tmp);
  if(iter!=res.end()){
    iter->second++;
  }

  for(int i=0; i<8; i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx<0) nx=n-1;
    if(nx>=n) nx=0;
    if(ny<0) ny=m-1;
    if(ny>=m) ny=0;

    tmp+=arr[nx][ny];
    dfs(nx,ny);
    tmp.pop_back(); //방금 추가한 거 취소
  }
}

int main(){
  cin>>n>>m>>k;
  arr.resize(n);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        char x; cin>>x;
        arr[i].push_back(x);
    }
  }
  vector<string> god;
  for(int i=0; i<k; i++){
    string x; cin>>x;
    god.push_back(x);
    res.insert({x,0});
    /* 아래처럼 지정
    {
      "abc": 0,
      "aa": 0,
      "xyz": 0
    }
    */
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      tmp.push_back(arr[i][j]);
      dfs(i,j);
      tmp.clear();
    }
  }
  for(int i=0; i<k; i++){
    cout<<res[god[i]]<<"\n";
  }
  return 0;
}