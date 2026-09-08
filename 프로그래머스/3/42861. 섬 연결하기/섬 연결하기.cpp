#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// union-find 알고리즘
vector<int> parent;

void makeSet(int n){
    parent.resize(n);
    for(int i=0; i<n; i++) parent[i]=i;
}

int find(int x){
    if(parent[x]==x) return x; // 자기가 곧 루트면 그대로 반환
    return parent[x]=find(parent[x]); // 부모쪽 타고 올라가서 찾기
}

void unionSet(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b) parent[a]=b;
}


int calc(int n, vector<vector<int>> &costs){
    int total=0;
    int costSize=costs.size();
    sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b){
        return a[2]<b[2]; // 오름차순
    });
    makeSet(n);
    for(int i=0; i<costSize; i++){
        if(find(costs[i][0])!=find(costs[i][1])){
            unionSet(costs[i][0], costs[i][1]);
            total+=costs[i][2];
        }
    }
    return total;
}

int solution(int n, vector<vector<int>> costs) { // n: 섬의 개수
    int answer=0;
    answer=calc(n,costs);
    return answer;
}