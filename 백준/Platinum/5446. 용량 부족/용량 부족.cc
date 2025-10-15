#include <bits/stdc++.h>
using namespace std;


struct Trie{
    map<char, Trie*> child; // 해당 문자를 루트로 하는 다음 노드: child['a']=trie노드 주소 ex) c-a-t
    bool end; bool removable;
    Trie(){
        end=false; // 문자열의 끝을 가리키는지
        removable=false; //삭제 가능한 노드인지
    }
    ~Trie(){ // 소멸자: 객체가 사라질 때 자동으로 호출되는 함수
        for(auto ch:child){
            if(ch.second) delete ch.second; //루트부터 모든 자식 노드를 재귀적으로 삭제
        }
    }
    void insert(string& s, int idx, bool rm){ // rm: 이 단어가 삭제 대상인지 보호 대상인지
        removable=rm;
        if(idx==s.length()){
            if(rm) end=true;
            return;
        }
        if(!child[s[idx]]){
            child[s[idx]]=new Trie();
        }
        child[s[idx]] -> insert(s,idx+1,rm); // 재귀호출로 다음 문자로 내려감: root -> 'c' -> 'l' -> ...
    }
};

int solve(Trie* node){
    if(node->removable) return 1; // 삭제 가능한 디렉토리인지
    int ans=node->end?1:0;
    for(auto ch:node->child){
        ans+=solve(ch.second);
    }
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        Trie root; int n1; cin>>n1;
        while(n1--){
            string s; cin>>s;
            root.insert(s, 0, true);
        }
        int n2; cin>>n2;
        while(n2--){
            string s; cin>>s;
            root.insert(s,0,false);
        }
        cout<<solve(&root) <<'\n';
    }
    return 0;
}
