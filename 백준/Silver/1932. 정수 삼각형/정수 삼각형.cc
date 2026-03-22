#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int a[501][501];

int main(){
  int n; cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<i+1; j++){
      cin>>a[i][j];
    }
  }
  for(int i=n-1; i>=1; i--){ // 아래부터 올라가면서 계산
    for(int j=0; j<i; j++){
      a[i-1][j] += max(a[i][j], a[i][j+1]); // 현재 위치에서 아래로 내려가는 두 경로 중 큰 값을 더하기
    }
  }

  cout<<a[0][0]<<endl;
  return 0;
}