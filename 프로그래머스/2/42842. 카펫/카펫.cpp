#include <cmath>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    for (int i = 3; i <= sqrt(total); i++) {
        if (total % i != 0) continue;
        int w = total / i;
        if ((w - 2) * (i - 2) == yellow) {
            answer.push_back(w);
            answer.push_back(i);
            break;   // 정답 찾았으니 반복 멈추기
        }
    }
    return answer;
}