#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    int result = 0;

    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int sum = a + b;
        result += sum;
        pq.push(sum);
    }

    cout << result;
}