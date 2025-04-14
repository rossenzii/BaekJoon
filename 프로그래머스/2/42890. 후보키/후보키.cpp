#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> candidates; // 이미 검사한 후보키를 등록

bool isSubset(int target, int previous){
    return ((target & previous) == previous); // 포함되는지
}

bool check_minimality(int target){
    for(int previous : candidates){
        if(isSubset(target, previous))
            return false;
    }
    return true;
}



bool check_uniqueness(int i, vector<vector<string>> relation){
    int k = relation[0].size();
    vector<string> combined;
    
    for(auto v: relation){
        string temp ="";
        for (int j=0; j<k; j++)
            if((i&(1<<j)) !=0 )
                temp+=v[j];
        if(find(combined.begin(), combined.end(), temp) != combined.end())
            return false;
        else
            combined.push_back(temp);
    }
    return true;
}

int solution(vector<vector<string>> relation){
    int k=relation[0].size();
    for(int i=1; i<(1<<k); i++){
        if(check_uniqueness(i, relation) && check_minimality(i))
            candidates.push_back(i);
    }
    int answer = candidates.size();
    return answer;
}