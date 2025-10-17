#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> count;

int main(){
    int n; cin>>n;
    vec.resize(n);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        vec.push_back(a);
    }
    int left=0; int right=vec.size()-1;
    int cnt=0;
    while(left<right){
        int distance=right-left-1;
        int power=min(vec[right], vec[left]);
        cnt=max(cnt, distance*power);
        
        if(vec[right]>vec[left]) left++;
        else right--;
    }
    cout<<cnt;
}