#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    int n; cin>>n;
    int cnt=0;
    bool flag;
    string s;
    while(n--){
        cin>>s;
        bool isUsed[26] = {false, };
        isUsed[s[0]-'a'] = true; //첫번째 문자는 무조건 사용
        flag = true; //그룹문자(단어에서 같은 문자가 연속해서 나오는 경우를 제외하고는 한 번만 나오는 단어)이다.
        
        for(int i=1; i<s.length(); i++){
            if(s[i] == s[i-1]) continue;
            if(isUsed[s[i]-'a']) {flag = false; break;} //이미 사용된 문자면 false 처리
            isUsed[s[i]-'a'] = true; //현재 문자는 사용한 걸로 표시
        }
        if(flag) cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}
