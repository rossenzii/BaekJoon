#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int cur;
    int prev;
    int next;
};

string solution(int n, int k, vector<string> cmd){ // 행개수, 현재행
    vector<int> prev(n), next(n);
    vector<bool> alive(n, true);
    for(int i=0; i<n; i++){
        prev[i]=i-1;
        next[i]=i+1;
    }
    next[n-1]=-1; // 마지막은 맨 처음으로..
    stack<Node> removed;
    for(string let:cmd){
        if(let[0]=='U'){
            int num=stoi(let.substr(2));
            while(num--){
                k=prev[k];
            }
        }
        else if(let[0]=='D'){
            int num=stoi(let.substr(2));
            while(num--){
                k=next[k];
            }
        }
        else if(let[0]=='C'){
            removed.push({k,prev[k],next[k]});
            alive[k]=false;
            if(prev[k]!=-1) next[prev[k]]=next[k]; // 걍 -1은 없다는 거 
            if(next[k]!=-1) prev[next[k]]=prev[k];
            if(next[k]!=-1) k=next[k];
            else k=prev[k];
        }
        else if(let[0]=='Z'){
            Node restore=removed.top();
            removed.pop();
            int c=restore.cur;
            int p=restore.prev;
            int nx=restore.next;
            alive[c]=true;
            if(p!=-1) next[p]=c; // 지금 값이 next로 간다.
            if(nx!=-1) prev[nx]=c;
            
        }
    }
    string answer="";
    for(int i=0; i<n; i++){
        if(alive[i]) answer+='O';
        else answer+='X';
    }
    return answer;
}