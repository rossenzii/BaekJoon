#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int players[], size_t players_len, int m, int k) {
    int answer = 0;
    int server[1000] = {0}; // 충분한 크기 가정

    for (size_t i = 0; i < players_len; i++) {
        int capacity = server[i] * m + (m - 1);

        if (players[i] > capacity) {
            int need = players[i] - capacity;
            int extra = (need + m - 1) / m; // 올림 처리

            for (int j = 0; j < k; j++) {
                server[i + j] += extra;
            }

            answer += extra;
        }
    }

    return answer;
}