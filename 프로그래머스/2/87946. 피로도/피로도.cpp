#include <string>
#include <vector>
using namespace std;

int answer = 0;

void dfs(int fatigue, int count, vector<bool>& visited, vector<vector<int>>& dungeons) {
    answer = max(answer, count);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && fatigue >= dungeons[i][0]) {
            visited[i] = true;
            dfs(fatigue - dungeons[i][1], count + 1, visited, dungeons);
            visited[i] = false; // 백트래킹: 다시 원상복구하고 다른 경우 탐색
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    vector<bool> visited(dungeons.size(), false);
    dfs(k, 0, visited, dungeons);
    return answer;
}