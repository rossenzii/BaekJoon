#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
stack<int> stk[8]; //stack 8개 (1~6줄)
int main(){
    int n, p; cin>>n>>p;
    int answ=0;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        if(stk[a].empty()){ //비었을 경우
            stk[a].push(b);
            answ++;
        }else if(stk[a].top()<b){
            stk[a].push(b);
            answ++;
        }else if(stk[a].top()>b){
            while(stk[a].top()>b){
                stk[a].pop();
                answ++;
                if(stk[a].empty()){
                    stk[a].push(b);
                    answ++;
                }
            }
            if(stk[a].top()<b){
                stk[a].push(b);
                answ++;
            }
        }
        
    }
    cout<<answ;
    return 0;
}