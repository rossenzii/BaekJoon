#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long getTime(const vector<int>& diffs, const vector<int>& times, int level){
    long long total_time=times[0];
    int size=diffs.size();
    for(int i=1; i<size; i++){
        if(diffs[i]<= level){
            total_time+=times[i];
        }else{
            int wrong=diffs[i]-level;
            total_time+=(long long)wrong * (times[i]+times[i-1]) + times[i];
        }
    }
    return total_time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left=1;
    int right=*max_element(diffs.begin(), diffs.end());
    int answer=right;
    while(left<=right){
        int mid=left+(right-left)/2; // 10부터 20 중간은 5가 아니라 10 더한 15
        if(getTime(diffs,times,mid)<=limit){
            answer=mid;
            right=mid-1; // 더 작은 범위 보기
        }else{
            left=mid+1; // 실패하면 level 크기 키워서 보기
        }
    }
    return answer;

}