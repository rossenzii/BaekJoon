#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int bag[121];                                
int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int sm = 0;                              
    for (int i = 0;i < info.size();i++)
    {
        int v = info[i][0], w = info[i][1];  
        sm += v;                             
        for (int j = m;j > w;j--)
            bag[j] = max(bag[j], bag[j - w] + v);
    }
    sm -= max(bag[m], bag[m - 1]);
    if (sm < n)
        answer = sm;
    else
        answer = -1;
    return answer;
}