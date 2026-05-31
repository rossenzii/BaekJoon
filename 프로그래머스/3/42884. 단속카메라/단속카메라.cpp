#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int sizeR=routes.size();
    sort(routes.begin(), routes.end(), cmp);
    int cam=routes[0][1]; // 첫 차량 진출점에 카메라 두기
    for(int i=1; i<sizeR; i++){
        if(routes[i][0]>cam){
            cam=routes[i][1];
            answer++;
        }
    }
    return answer;
}