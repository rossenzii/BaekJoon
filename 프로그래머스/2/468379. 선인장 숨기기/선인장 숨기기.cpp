#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

// 1D 슬라이딩 윈도우 최솟값
vector<int> slideMin1D(const vector<int>& v, int size){
  vector<int> result;
  deque<int> dq;
  for(int i=0; i<(int)v.size(); i++){
    while(!dq.empty() && dq.front()<=i-size) dq.pop_front(); // i는 현재 위치, size는 윈도우 크기 -> front가 범위 지났으면 벗어난 것
    while(!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back(); // 현재값(v[i]가 deque 뒤쪽 값보다 작거나 같으면 dq.back() 제거(최소가 어차피 아니니까)
    dq.push_back(i);
    if(i>=size-1) result.push_back(v[dq.front()]); // 결과에 계속 기록 e.g. 1 1 2 1 1
  }
  return result;
}

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops){
  vector<vector<int>> rainTime(m, vector<int>(n, INT_MAX)); // 시간 기록
  for(int i=0; i<(int)drops.size(); i++){
    rainTime[drops[i][0]][drops[i][1]] = i+1;
  }
  vector<vector<int>> rowMin(m); // 1. 행마다 가로 슬라이딩 윈도우 최솟값
  for(int i=0; i<m; i++){
    rowMin[i] = slideMin1D(rainTime[i], w);
  }
  int cols = n-w+1;
  int rRows = m-h+1;
  vector<vector<int>> winMin(rRows, vector<int>(cols)); // 2. 열에 세로 윈도우마다 최솟값
  for(int j=0; j<cols; j++){
    vector<int> col(m);
    for(int i=0; i<m; i++) col[i] = rowMin[i][j]; // col[i]에 j번째 열 정보 저장
    vector<int> cm = slideMin1D(col, h); // 최소 찾기
    for(int i=0; i<rRows; i++) winMin[i][j]=cm[i]; // 최소 찾은 거 winMin에 저장
  }
  int bestVal=0;
  int bestR = 0, bestC=0;
  for(int i=0; i<rRows; i++){
    for(int j=0; j<cols; j++){
      if(winMin[i][j] > bestVal){ // 최솟값이 가장 큰 경우
        bestVal = winMin[i][j];
        bestR = i;
        bestC = j;
      }
    }
  }
  return {bestR, bestC};
}