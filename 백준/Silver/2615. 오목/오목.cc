#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int board[19][19]={0};
int input;
int dx[]={1,0,1,-1};
int dy[]={0,1,1,1};
int backwardX;
int backwardY;

bool isValid(int x, int y){
    return x>=0 && x<19 && y>=0 && y<19;
}


bool checkFive(int row, int column){
    
    if(board[row][column]==0) return false;
    
    for(int dir=0; dir<4; dir++){
        int count=1;
        int x= row+dx[dir];
        int y= column+dy[dir];
        while(isValid(x,y) && board[x][y]==board[row][column]){
            count++;
            x+=dx[dir];
            y+=dy[dir];
        }
        int forwardX = x; //연속의 맨앞
        int forwardY = y;
        
        x=row-dx[dir];
        y=column-dy[dir];
        while(isValid(x,y)&&board[x][y]==board[row][column]){
            count++;
            x-=dx[dir];
            y-=dy[dir];
        }
        backwardX=x+dx[dir]; //연속의 맨 끝
        backwardY=y+dy[dir];
        
        if(count==5){// 5개인지 확인하기
            if((!isValid(forwardX, forwardY) || board[forwardX][forwardY] !=board[row][column]) &&
               (!isValid(backwardX-dx[dir], backwardY-dy[dir]) || board[backwardX-dx[dir]][backwardY-dy[dir]]!=board[row][column])){
                return true;
            }
        }
    }
    return false;
    
}
int main(){
    //1. 바둑판 입력받기
    for(int i=0; i<19;i++){
        for(int j=0; j<19; j++){
            cin>>board[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (checkFive(i, j)) {
                cout << board[i][j] << "\n" << backwardX + 1 << " " << backwardY + 1 << endl;
                return 0;
            }
        }
    }
    cout<<0<<'\n';
    return 0;
}