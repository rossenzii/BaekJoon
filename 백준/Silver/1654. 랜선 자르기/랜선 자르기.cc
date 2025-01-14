#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    int k,n; cin>>k>>n;
    
    vector<int> length(k);
    int max_length=0;
    for(int i=0; i<k; i++){
        cin>>length[i];
        max_length=max(max_length, length[i]); //최대 길이 지정
    }
    
    long long left = 1;
    long long right = max_length;
    long long mid = (left+right)/2;
    
    while(left<=right){
        int count=0;
        for(int i=0; i<k; i++){
            count +=length[i]/mid;
        }
        if(count >= n){
            left = mid+1;
        }
        else {
            right = mid-1;
        }
        mid=(left+right)/2;
    }
    cout<<mid<<endl;
    return 0;
    
}