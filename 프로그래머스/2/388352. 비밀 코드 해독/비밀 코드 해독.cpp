#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 1~30 중 5개 선정, 
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> nums(n);
    int answer=0;
    for(int i=0; i<n; i++) nums[i]=i+1;
    vector<bool> selector(n, false);
    fill(selector.end()-5, selector.end(), true);
    int m=q.size();
    do{
        vector<int> combo;
        for(int i=0; i<n; i++) if(selector[i]) combo.push_back(nums[i]);
        bool ok=true;
        for(int i=0; i<m; i++){
            int cnt=0, a=0, b=0;
            while(a<5 && b<5){
                if(combo[a]==q[i][b]) {cnt++; a++; b++;}
                else if (combo[a]<q[i][b]) a++;
                else b++;
            }
            if(cnt !=ans[i]) {ok=false; break;}
        }
        if(ok) answer++;
    }while(next_permutation(selector.begin(), selector.end()));
    
    return answer;
}