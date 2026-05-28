#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int removeFood(
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    >& pq,
    long long k
){

    long long prevMin = 0;

    while(!pq.empty()){

        long long restFood = pq.size();

        pair<int,int> top = pq.top();

        long long foodTime = top.first;

        long long removedLayer =
            (foodTime - prevMin) * restFood;

        if(k >= removedLayer){

            k -= removedLayer;

            prevMin = foodTime;

            pq.pop();
        }

        else{

            vector<pair<int,int>> remain;

            while(!pq.empty()){

                remain.push_back(pq.top());

                pq.pop();
            }

            sort(remain.begin(),
                 remain.end(),
                 [](pair<int,int> a,
                    pair<int,int> b){

                    return a.second < b.second;
                 });

            return remain[k % restFood].second;
        }
    }

    return -1;
}

int solution(vector<int> food_times, long long k) {

    long long total = 0;

    for(int food : food_times){

        total += food;
    }

    if(total <= k) return -1;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    for(int i=0; i<food_times.size(); i++){

        pq.push({food_times[i], i+1});
    }

    return removeFood(pq, k);
}