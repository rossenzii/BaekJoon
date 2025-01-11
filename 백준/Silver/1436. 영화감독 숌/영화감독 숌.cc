#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    string s;
    int num; cin>>num;
    int chk=0;
    for(int title=666; ;title++){
        s=to_string(title);
        if(s.find("666") !=-1) { //666을 찾음
            chk++;
            if(chk ==num){
                cout<<title;
                break;
            }
        }
    }
    return 0;
}

