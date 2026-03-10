#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> houses(n);
    
    for(int i = 0; i < n; i++){
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());
    cout << houses[(n-1)/2];

    return 0;
}