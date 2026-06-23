#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    int n=a.size();
    vector<int> count(n, 0);
    for(int i=0; i<n; i++){
        count[a[i]]++;
    }
    int maxLen=0;
    for(int X=0; X<n; X++){
        if(count[X]*2<=maxLen) continue;
        int curLen=0;
        for(int i=0; i<n-1;){
            if(a[i]!=a[i+1]&&(a[i]==X || a[i+1]==X)){
                curLen+=2;
                i+=2;
            }else{
                i+=1;
            }
        }
        maxLen=max(maxLen, curLen);
        
    }
    return maxLen;
}