#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long start=0;
    long long end = (long long)*max_element(times.begin(), times.end())*n;
    long long answer=end;
    while(start<=end){
        long long mid=(start+end)/2;
        long long ppl=0;
        for(int t:times){
            ppl+=mid/t;
            if(ppl>=n) break; // 다 처리 가능하면 조기 종료
        }
        if(ppl>=n){
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return answer;
}