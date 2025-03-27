#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

set<string> s;
vector<bool> visited(9,0);
vector<string> user, ban;

bool check_ban(string str, string ban){
    if(str.size() != ban.size())
        return 0;
    for(int i=0; i<ban.size(); i++){
        if(ban[i]=='*')
            continue;
        if(str[i]!=ban[i])
            return 0;
    }
    return 1;
}

void dfs(int idx){
    if(idx == ban.size()){ //ban 끝까지 다 돌았을 때
        string str = "";
        for(int i=0; i<user.size(); i++)
            if(visited[i]==1)
                str += i+'0';
        s.insert(str);
        return;
    }
    for(int i=0; i<user.size(); i++){
        if(visited[i]==1) continue;
        if(check_ban(user[i],ban[idx])==1){
            visited[i]=1;
            dfs(idx+1);
            visited[i]=0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id){
    user = user_id;
    ban = banned_id;
    dfs(0);
    return s.size();
}