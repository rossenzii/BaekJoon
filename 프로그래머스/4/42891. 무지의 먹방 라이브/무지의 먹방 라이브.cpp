#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
    // 모든 음식을 다 먹을 수 있는 경우
    long long total = 0;
    for (int t : food_times) {
        total += t;
    }
    if (total <= k) {
        return -1;
    }
    
    // 우선순위 큐: (음식 시간, 음식 번호)
    // 음식 시간이 작은 순으로 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({food_times[i], i + 1});  // 번호는 1부터
    }
    
    long long sum_value = 0;   // 지금까지 먹는데 쓴 시간
    long long previous = 0;    // 이전에 제거된 음식의 시간
    long long length = food_times.size();  // 남은 음식 개수
    
    // 음식을 통째로 제거할 수 있는 동안 반복
    while (sum_value + (pq.top().first - previous) * length <= k) {
        auto now = pq.top();
        pq.pop();
        
        sum_value += (now.first - previous) * length;
        length--;
        previous = now.first;
    }
    
    // 남은 음식 중에서 몇 번째 음식인지 확인
    long long target = k - sum_value + 1;
    
    // 남은 음식들을 원래 번호 순으로 정렬
    vector<pair<int, int>> remaining;
    while (!pq.empty()) {
        remaining.push_back(pq.top());
        pq.pop();
    }
    
    // 음식 번호(second) 기준으로 정렬
    sort(remaining.begin(), remaining.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    
    // target번째 음식 찾기 (순환 고려)
    long long idx = (target - 1) % length;
    
    return remaining[idx].second;
}