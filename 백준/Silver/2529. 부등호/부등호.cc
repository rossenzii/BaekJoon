#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k;
char sign[11]; //부등호 담는 수열
int num[11]; //조합으로 만들어진 수열
bool ch[11]; //숫자 중복 불허
vector<string> ans; //부등호 만족하는 수열을 저장하는 벡터string max, min;

bool SignCheck(int a, int b, char oper){
    if(oper =='<'){
        if(a>b) return false;
    }else{
        if(a<b) return false;
    }
    return true;
}

void Combination(int index, string num){
    //index: 선택할 숫자 자리 (0~9)
    if(index==(k+1)){ //완료 시
        ans.push_back(num);
        return;
    }
    
    for(int i=0; i<=9; i++){
        if(ch[i]) continue; // 사용한 숫자는 지나치기
        if(index==0 || SignCheck(num[index-1]-'0', i, sign[index-1])){
            ch[i]=true; //선택
            Combination(index+1, num + to_string(i)); //다음 자리수 선택을 위한 재귀 호출
            ch[i]=false;
        }
    }
}

int main(){
    fastio;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>sign[i]; //부등호 입력 받기
    }
    Combination(0, "");
    sort(ans.begin(), ans.end());
    cout << ans.back() << '\n' << ans.front();
    return 0;
}