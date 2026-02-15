#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);


int K, L, B;
void rotate_key(vector<vector<int>> &mat){
    int M=mat.size();
    vector<vector<int>> temp(M, vector<int> (M));
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            temp[i][j]=mat[M-(j+1)][i];
        }
    }
    mat=temp;
}

bool check(vector<vector<int>> &board, vector<vector<int>> &key, int y, int x){
    bool ret=true;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            board[i+y][j+x]+=key[i][j]; // key를 board에 더하기
        }
    }
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            if(board[i+K-1][j+K-1]!=1){ // board의 중앙 부분이 모두 1이 되어야 함
                ret=false;
                break;
            }
        }
    }
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            board[i+y][j+x]-=key[i][j]; // key를 board에서 빼기: 다음 회차에 key를 board에 더할 때 영향을 주지 않도록 하기 위해
        }
    }
    return ret;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    K=key.size(), L=lock.size();
    B=2*K+L-2; // board의 크기
    vector<vector<int>> board(B, vector<int> (B,0));
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            board[i+K-1][j+K-1]=lock[i][j]; // board의 중앙 부분에 lock을 배치
        }
    }
    for(int r=0; r<4; r++){
        for(int i=0; i<=B-K; i++){
            for(int j=0; j<=B-K; j++){
                // key를 board에 더했을 때 board의 중앙 부분이 모두 1이 되는 경우가 있으면 true
                if(check(board, key, i, j)) return true; 
            }
        }
        rotate_key(key);
    }
    return false;
}