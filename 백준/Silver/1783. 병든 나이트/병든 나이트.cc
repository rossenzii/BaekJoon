#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main () {
    fastio;
    int n, m;
    
    cin >> n >> m;
        
    if (n == 1) cout << 1;
    else if (n == 2) cout << min(4, (m + 1) / 2);
    else if (m < 7) cout << min(4, m);
    else cout << m - 2;
}