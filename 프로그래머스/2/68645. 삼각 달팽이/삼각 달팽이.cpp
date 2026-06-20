#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> matrix(n);
    for(int i=0; i<n; i++){
        matrix[i].resize(i+1,0);
    }
    int dr[]={1,0,-1};
    int dc[]={0,1,-1};
    int row=-1, col=0;
    int num=1;
    int direction=0;
    for(int i=0; i<n; i++){ // 방향을 바꾸는 횟수
        for(int j=0; j<n-i; j++){ // 한 방향으로 직진하며 숫자를 채우는 칸의 개수 e.g. 4->3->2...
            row+=dr[direction];
            col+=dc[direction];
            matrix[row][col]=num++;
        }
        direction=(direction+1)%3;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            answer.push_back(matrix[i][j]);
        }
    }
    return answer;
}