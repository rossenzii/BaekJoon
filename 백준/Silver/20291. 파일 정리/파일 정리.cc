#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<string, int> cnt;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;

        int dot = name.find('.');
        string extension = name.substr(dot + 1);

        cnt[extension]++; // 개수 증가
    }

    for(auto &p : cnt){
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}