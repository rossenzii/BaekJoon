#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
struct FOOD
{
    int Food_Time;
    int Num;
};
 
FOOD Food[200010];
 
bool Cmp(FOOD A , FOOD B)
{
    if (A.Food_Time < B.Food_Time) return true;
    return false;
}
 
bool Cmp2(FOOD A, FOOD B)
{
    if (A.Num < B.Num) return true;
    return false;
}
 
int solution(vector<int> food_times, long long k)
{
    int N = food_times.size();
    for (int i = 0; i < N; i++)
    {
        Food[i].Food_Time = food_times[i];
        Food[i].Num = i + 1;
    }
    sort(Food, Food + N, Cmp);
 
    int Prev_Time = 0;
    int Temp_N = N;
    for (int i = 0; i < N; i++ , Temp_N--)
    {
        long long Diff = (long long)(Food[i].Food_Time - Prev_Time) * Temp_N;
        if (Diff == 0) continue;
        if (Diff <= k)
        {
            k = k - Diff;
            Prev_Time = Food[i].Food_Time;
        }
        else
        {
            k = k % Temp_N;
            sort(Food + i, Food + N, Cmp2);
            return Food[i + k].Num;
        }
 
    }
    return -1;
}