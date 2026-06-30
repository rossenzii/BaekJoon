#include <vector>
#include <algorithm>

using namespace std;

// 판별 함수: mid 시간 안에 금과 은을 옮길 수 있는가?
bool can_transport(long long time, long long a, long long b, long long goal_total, 
                   const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t) {
    long long total_gold = 0;
    long long total_silver = 0;
    long long total_both = 0;

    for (int i = 0; i < g.size(); i++) {
        long long move_time = t[i];
        long long weight = w[i];
        
        // 왕복 횟수 계산
        long long count = (time + move_time) / (move_time * 2);
        
        // 해당 도시에서 최대로 옮길 수 있는 무게
        long long max_capacity = count * weight;
        
        // 각 도시별 금, 은, 합계 제한
        total_gold += min((long long)g[i], max_capacity);
        total_silver += min((long long)s[i], max_capacity);
        total_both += min((long long)g[i] + s[i], max_capacity);
    }

    // 조건 검사: 세 가지 조건을 모두 만족해야 함
    return (total_gold >= a && total_silver >= b && total_both >= goal_total);
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long low = 0;
    long long high = 4e14; // 충분히 큰 값
    long long answer = high;
    long long goal_total = (long long)a + b;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (can_transport(mid, a, b, goal_total, g, s, w, t)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}