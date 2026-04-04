#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int map[10][10];
vector<pair<int,int>> empties;

bool printNumber(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
    return true;
}

bool isPossible(int x, int y, int k){
    for(int i=1; i<=9; i++){
        if(map[x][i]==k && i!=y) return false;
        if(map[i][y]==k && i!=x) return false;
        int nx=(x-1)/3*3+1+(i-1)/3;
        int ny=(y-1)/3*3+1+(i-1)%3;
        if(map[nx][ny]==k && !(nx==x && ny==y)) return false;
    }
    return true;
}

void backTracking(int idx){
    if(idx==(int)empties.size()){  // ← 캐스팅 추가
        printNumber();
        exit(0);
    }

    int x=empties[idx].first;
    int y=empties[idx].second;
    for(int k=1; k<=9; k++){
        if(isPossible(x,y,k)){
            map[x][y]=k;
            backTracking(idx+1);
            map[x][y]=0;
        }
    }
}

int main(){
    for(int i=1; i<=9; i++){
        string str;
        cin >> str;
        for(int j=1; j<=9; j++){
            map[i][j]=str[j-1]-'0';
            if(map[i][j]==0)
                empties.push_back(make_pair(i,j));
        }
    }
    backTracking(0);  // ← 누락된 호출 추가!
    return 0;
}