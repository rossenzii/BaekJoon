#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

char arr[51][51];
char white_arr[8][8] = {
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W'
};

char black_arr[8][8] = {
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
    'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B'
};

int white_first(int x, int y){
    int result =0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[x+i][y+j]!=white_arr[i][j])
                result++;
        }
    }
    return result;
}

int black_first(int x, int y){
    int result =0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[x+i][y+j]!=black_arr[i][j])
                result++;
        }
    }
    return result;
}

int main(){
    fastio;
    int N, M, result=64; cin>>N>>M; //세로, 가로
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    int t_white, t_black;
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            t_white = white_first(i, j);
            t_black = black_first(i, j);
            if(t_white<t_black){
                result = (t_white<result)? t_white:result;
            }
            else{
                result = (t_black<result)?t_black:result;
            }
        }
    }
    cout<<result<<'\n';
}