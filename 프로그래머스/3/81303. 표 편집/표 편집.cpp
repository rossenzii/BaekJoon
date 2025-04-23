#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


string solution(int n, int k, vector<string> cmd){
    vector<int> prev(n), next(n);
    stack<int> removed;
    
    for(int i=0; i<n; i++){
        prev[i]=i-1;
        next[i]=i+1;
    }
    next[n-1]=-1;
    int cur=k;
    
    for(const string& s: cmd){
        char command = s[0];
        int value = 0;
        if(s.size()>1) value = stoi(s.substr(2));
        
        if(command=='U'){
            while(value--){
                cur=prev[cur];
            }
        }else if(command=='D'){
            while(value--){
                cur=next[cur];
            }
        }else if(command=='C'){
            removed.push(cur);
            if(prev[cur]!=-1) next[prev[cur]]=next[cur];
            if(next[cur]!=-1) prev[next[cur]]=prev[cur];
            
            cur = (next[cur] != -1) ? next[cur] : prev[cur];
        } else if (command == 'Z') {
            int restore = removed.top();
            removed.pop();
            if (prev[restore] != -1) next[prev[restore]] = restore;
            if (next[restore] != -1) prev[next[restore]] = restore;
        }
    }
        
    string answer(n, 'O');
    while (!removed.empty()) {
        answer[removed.top()] = 'X';
        removed.pop();
    }
    
    return answer;
    
}