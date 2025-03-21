#include <string>
#include <vector>
using namespace std;


int answer= 1;
int s=0;
int w=0;
void dfs(int curr_idx, int w, int s, vector<int> nextNode, vector<int> info, vector<vector<int>> v){
    //3. 현재 노드가 양/늑대인지 확인
    int animal = info[curr_idx];
    if(!animal) s++; //양이면 s증가
    else w++;
    //4. 양의 개수 업뎃
    answer = max(answer, s);
    if(w>=s) return;
    //5. nextNode 방문하고 나면 방문한 노드는 nextNode에서 제거하고, nextNode[i]의 자식 노드를 새로운 nextNode에 추가
    for(int i=0; i<nextNode.size(); i++){
        vector<int> next = nextNode; //기존 리스트 복사
        next.erase(next.begin()+i); //현재 방문한 노드는 제서
        for(int j=0; j<v[nextNode[i]].size(); j++)
            next.push_back(v[nextNode[i]][j]);
        dfs(nextNode[i],w,s, next, info, v);
    }
}


int solution(vector<int> info, vector<vector<int>> edges){
    // 1. edge를 트리 구조로 변환 -- v[i]에 i번 노드에 어떤 자식이 있는지 자식 노드 저장
    vector<vector<int>> v(info.size());
    for(int i=0; i<edges.size(); i++)
        v[edges[i][0]].push_back(edges[i][1]);
    // 2. 0번 노드에서 시작할 수 있는 다음 노드 설정
    vector<int> nextNode;
    for(int i=0; i<v[0].size(); i++)
        nextNode.push_back(v[0][i]);
    dfs(0,0,0,nextNode,info,v);
    
    return answer;
}