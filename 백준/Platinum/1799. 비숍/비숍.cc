#include <string>
#include <deque>
#include <map>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int t;
int ans[2];
int chess[11][11];
int l[20];
int r[20];

void bishop(int row, int col, int count, int color){ //count: 현재까지 bishop 수
    if(col>=t){ // 한줄 다 돌면
        row++;
        if(col%2==0) col=1; // 짝수
        else col=0; // 홀수
    }
    if(row>=t){
        ans[color]=max(ans[color],count);
        return;
    }
    if(chess[row][col]&&!l[col-row+t-1]&&!r[row+col]){
        //l: 오른쪽 ↘↖ 대각선이 비어 있는가 -> n-1은 음수 방지
        // r: 왼쪽 ↙↗ 대각선이 비어 있는가 -> 대각선에 있으면 r+c 값이 동일함
        l[col-row+t-1]=r[row+col]=1; // 비숍을 현재 칸에 놨다고 하기
        bishop(row, col+2, count+1, color); //col+2: 다음 칸으로 이동
        l[col-row+t-1]=r[row+col]=0; //탐색 끝나면 원상 복구: 놓을 수 있는 모든 비숍 배치를 시도하기 위함
    }
    bishop(row,col+2,count,color); // 비숍을 안 넣고 넘어감
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            cin>>chess[i][j];
        }
    }
    bishop(0, 0, 0, 0);
    bishop(0,1,0,1);
    cout<<ans[0]+ans[1];
    return 0;
}
