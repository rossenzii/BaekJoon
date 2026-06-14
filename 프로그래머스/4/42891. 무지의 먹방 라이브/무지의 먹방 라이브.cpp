#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int removeFood(priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> &pq, long long k){
    long long prevMin=0; // 직전에 다 먹은 음식 양
    while(!pq.empty()){
        long long restFood = pq.size(); // 남은 음식 개수
        pair<int,int> top = pq.top(); 
        long long foodTime = top.first;
        long long removedLayer = (foodTime-prevMin)*restFood; //음식을 다 먹기 위해 필요한 총 시간
        if(k>=removedLayer){ 
            k-=removedLayer;
            prevMin=foodTime; // 밑 바닥층 갱신
            pq.pop();
        }
        else{
            vector<pair<int, int>> remain;
            while(!pq.empty()){ // 다시 옮겨 담기
                remain.push_back(pq.top());
                pq.pop();
            }
            sort(remain.begin(), remain.end(), // 원래 음식 순서대로 담기
                 [](const pair<int, int>& a, const pair<int,int>& b){
                     return a.second < b.second;
                 });
            return remain[k%restFood].second;
        }
    }
    return -1;
}

int solution(vector<int> food_times, long long k) {
    long long total=0;
    for(int food:food_times){
        total+=food;
    }
    if(total<=k) return -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<food_times.size(); i++){
        pq.push({food_times[i], i+1});
    }
    return removeFood(pq, k);
}