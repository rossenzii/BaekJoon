#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> candidateKeys;

bool checkMinimal(vector<int> cols){
    for(auto key:candidateKeys){
        bool contain=true;
        for(int k : key){
            if(find(cols.begin(), cols.end(), k)==cols.end()){
                contain=false;
                break;
            }
        }
        if(contain) return false;
    }
    return true;
}
bool checkUnique(vector<int> cols, int c, vector<vector<string>> relation){
    set<string> uniq;
    for(int i=0; i<c; i++){
        string s="";
        for(int col: cols){
            s+=relation[i][col];
            s+=',';
        }
        uniq.insert(s);
    }
    return uniq.size()==c;
}

int solution(vector<vector<string>> relation) {
    int columnSize=relation[0].size();
    int answer = 0;
    
    for(int bit=1; bit<(1<<columnSize); bit++){
        vector<int> cols;
        for(int i=0; i<columnSize; i++){
            if(bit & (1<<i)){
                cols.push_back(i);
            }
        }
        
        if(checkMinimal(cols) && checkUnique(cols, relation.size(), relation)){
            candidateKeys.push_back(cols);
            answer++;
        }
    }
    
    return answer;
}