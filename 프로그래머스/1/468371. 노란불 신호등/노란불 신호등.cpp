#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

bool isYellow(int t, vector<int>& signal){
  int G=signal[0];
  int Y=signal[1];
  int R=signal[2];
  int cycle = G+Y+R;
  int t_mod = (t-1)%cycle;
  return (t_mod >= G && t_mod < G + Y);
}

int solution(vector<vector<int>> signals) {
    int Limit = 1e9;
    for(int t=1; t<Limit; t++){
        bool allYellow = true;
        for(int i=0; i<signals.size(); i++){
          if(!isYellow(t, signals[i])){
              allYellow=false;
              break;
          }
        }
        if(allYellow) return t;
    }
    return -1;
}
