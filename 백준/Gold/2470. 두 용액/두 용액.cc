#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 2000000001
typedef long long ll;
using namespace std;

int main(){
    fastio;
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int minValue =INF;
    
    int left = 0, right=n-1;
    int minLeft = 0;
    int minRight = 0;
    
    while(left != right){
        int sum = v[left]+v[right];
        
        if(minValue > abs(sum))
        {
            minValue = abs(sum);
            minLeft = v[left];
            minRight = v[right];
        }
        if(sum>0)
            right--;
        else
            left++;
    }
    cout<<minLeft<<' '<<minRight;
    return 0;
}