#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    for(int tcase=1; tcase<=t; tcase++){
        int n; cin>>n;
        string str;
        vector<string> vec;
        for(int i=0; i<n; i++){
            cin>>str;
            vec.push_back(str);
        }
        sort(vec.begin(), vec.end());
        bool flag=true;
        for(int i=0; i<vec.size()-1; i++){
            string cur=vec[i]; //제일 처음 것
            string next=vec[i+1];
            flag=true;
            if(cur.length()>next.length()) continue;
            if(cur==next.substr(0, cur.length())){
                flag=false;
                break;
            }
        }
        if(!flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}