#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int k; cin>>k;
    int answ=0;
    stack<int> sck;
    while(k--){
        int a; cin>>a;
        if(a==0){
            sck.pop();
        } else{
            sck.push(a);
        }
    }
    while(!sck.empty()){
        answ+=sck.top();
        sck.pop();
    }
    cout<<answ;
    return 0;
}