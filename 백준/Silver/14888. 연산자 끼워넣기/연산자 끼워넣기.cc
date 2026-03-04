#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int n;
vector<int> nums;
int plusCnt=0, minusCnt=0, mulCnt=0, diviCnt=0;
int maxVal = INT_MIN, minVal = INT_MAX;

void dfs(int idx, int result, int plusCnt, int minusCnt, int mulCnt, int diviCnt) {
    if (idx == n+1) { // 숫자 다 썼으면
        maxVal = max(maxVal, result);
        minVal = min(minVal, result);
        return;
    }

    if (plusCnt > 0)  dfs(idx+1, result + nums[idx], plusCnt-1, minusCnt, mulCnt, diviCnt);
    if (minusCnt > 0) dfs(idx+1, result - nums[idx], plusCnt, minusCnt-1, mulCnt, diviCnt);
    if (mulCnt > 0)   dfs(idx+1, result * nums[idx], plusCnt, minusCnt, mulCnt-1, diviCnt);
    if (diviCnt > 0)  dfs(idx+1, result / nums[idx], plusCnt, minusCnt, mulCnt, diviCnt-1);
}


int main(){
  cin>>n;
  nums.assign(n+1, 0);
  vector<int> op; // 0 2 2 1
  for(int i=1; i<=n; i++){
    int num; cin>>num;
    nums[i]=num;
  }
  for(int i=1; i<=4; i++){
    int num; cin>>num;
    op.push_back(num);
    if(i==1) plusCnt=num;
    else if(i==2) minusCnt=num;
    else if(i==3) mulCnt=num;
    else if(i==4) diviCnt=num;
  }
  dfs(2, nums[1], plusCnt, minusCnt, mulCnt, diviCnt);
  cout<<maxVal<<"\n"<<minVal;
  
}