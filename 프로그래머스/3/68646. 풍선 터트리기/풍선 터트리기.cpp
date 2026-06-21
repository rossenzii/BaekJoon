#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n=a.size();
    vector<int> left_min(n);
    vector<int> right_min(n);
    left_min[0]=a[0];
    for(int i=1; i<n; i++){
        left_min[i]=min(left_min[i-1], a[i]);
    }
    right_min[n-1]=a[n-1];
    for(int i=n-2; i>=0; i--){
        right_min[i]=min(right_min[i+1], a[i]);
    }
    for(int i=0; i<n; i++){
        if(a[i]>left_min[i] && a[i]>right_min[i]) {
            continue;
        }
        answer++;
    }
    
    return answer;
}