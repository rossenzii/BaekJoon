#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    int k;
    cin >> k;

    vector<pair<int, string>> ppl;
    int n = k; 

    while(k--){
        int age;
        string name;
        cin >> age >> name;
        ppl.push_back({age, name});
    }

    stable_sort(ppl.begin(), ppl.end(), compare);

    for(int i = 0; i < n; i++){ 
        cout << ppl[i].first << ' ' << ppl[i].second << '\n';
    }
}