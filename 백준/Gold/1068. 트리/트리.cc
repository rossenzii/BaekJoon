#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

vector<vector<int>> arr;
vector<bool> visited;

int n;
int removeNode;
int leaf=0;
int root=0;

void input(){
    cin>>n;
    arr.resize(n);
    visited.resize(n);
    
    for(int node=0; node<n; node++){
        int parent;
        cin>>parent;
        if(parent==-1){
            root=node;
            continue;
        }
        arr[parent].push_back(node);
    }
    cin>>removeNode;
}

void dfs(int start){
    if(visited[start]) return;
    visited[start]=true;
    int flag=0;
    for(int next: arr[start]){
        if(visited[next]==false){
            dfs(next);
            flag=1;
        }
    }
    if(!flag) leaf++;
}

void game(){
    visited[removeNode] = true;
    dfs(root);
    cout<<leaf;
}
int main(){
    input();
    game();
}