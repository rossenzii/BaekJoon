#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e8;
    int weakSize = weak.size();
    for(int i=0; i<weakSize-1; i++){
      weak.push_back(weak[i]+n); // 원형이니까
    }
    sort(dist.begin(), dist.end());
    do{
      for(int i=0; i<weakSize; i++){
        // 1. 초기화
        int start=weak[i]; // 현재 시작 취약지점
        int end=weak[i+weakSize-1]; // 현재 시작 취약지점에서 가장 멀리 있는 취약지점(마지막)
        // 2. 친구 이동
        for(int j=0; j<dist.size(); j++){
          start+=dist[j]; // 친구가 dist[j]만큼 이동
          if(start>=end){ // 친구가 end까지 이동할 수 있다면
            answer=min(answer, j+1);
            break;
          }
          for(int z=i+1; z<i+weakSize; z++){
            if(weak[z]> start){ // start보다 멀리 있는 취약지점이 있다면
              start=weak[z]; // 친구가 다음 취약지점까지 이동
              break;
            }
          }
        }
      }
    } while(next_permutation(dist.begin(), dist.end())); // 친구의 이동 거리 순열
    if(answer == 1e8) return -1; // 모든 경우의 수를 탐색했는데도 취약지점을 모두 점검할 수 없다면 -1 반환
    return answer;

}