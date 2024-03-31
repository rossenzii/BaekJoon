#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool IsError(const string&s){
    if(s.find('_')==string::npos) return isupper(s[0]);
    else{
        if (s[0]=='_' ||s.back()=='_') return 1;
        for (auto&i :s) if(isupper(i)) return 1;
        return s.find("__") != string::npos; // __를 찾으면 true(1) 없으면 false(0) 반환
    }
}

string JavaToCpp(string s){
    string ret;
    for(int i=0; i<s.size();i++){
        if(isupper(s[i])){
            ret+='_';
            ret+=tolower(s[i]);
        }
        else{ ret+=s[i];}
    }
    return ret;
}

string CppToJava(string s){
    //string ret;
    for(int i=0; i<s.size();i++){
        if(s[i]=='_') {
            s.erase(i,1);
            s[i]=toupper(s[i]);}
    }
    return s;
}
int main(){
    fastio;
    string s; cin>>s;
    if(IsError(s)) cout<<"Error!"<<'\n';
    else{
        bool flag = s.find('_')==string::npos; //_못찾으면 -1반환하는데 이는 npos와 일치 ==참
        cout<<(flag?JavaToCpp:CppToJava)(s)<<'\n';
    }
}
