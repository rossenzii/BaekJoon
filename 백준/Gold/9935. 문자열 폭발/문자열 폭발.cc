#include<iostream>
#include<string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int main(){
    fastio;
    string str,bomb,spc="";
    cin>>str>>bomb;
    
    for(int i=0; i<str.length(); i++){ 
        spc+=str[i];
        if(spc.length()>=bomb.length()){
            bool flag=true;
            for(int j=0; j<bomb.length(); j++){
                if(spc[spc.length()-bomb.length()+j] != bomb[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                spc.erase(spc.end()-bomb.length(), spc.end()); }
        }
    }
    if(spc.empty()) cout<<"FRULA"<<'\n';
    else cout<<spc<<'\n';
    return 0;
}