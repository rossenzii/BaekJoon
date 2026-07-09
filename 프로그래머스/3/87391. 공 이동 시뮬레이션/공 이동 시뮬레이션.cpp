#include <string>
#include <vector>

using namespace std;


long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long startX= x, endX=x;
    long long startY= y, endY=y;
    for(int i=queries.size()-1; i>=0; i--){
        int command=queries[i][0];
        long long dx=queries[i][1];
        
        if(command==0){ // 열감소
            if(startY!=0) startY+=dx;
            endY+=dx;
            if(endY>=m) endY=m-1;
        }
        else if(command==1){ // 열증가
            if(endY!=m-1) endY-=dx;
            startY-=dx;
            if(startY<0) startY=0;
        }
        else if(command==2){ // 행감소
            if(startX!=0) startX+=dx;
            endX+=dx;
            if(endX>=n) endX=n-1;
        }
        else if(command==3){ // 행증가
            if(endX!=n-1) endX-=dx;
            startX-=dx;
            if(startX<0) startX=0;
        }
        if (startX >= n || endX < 0 || startY >= m || endY < 0 || startX > endX || startY > endY) {
            return 0;
        }
    }
    return (endX - startX + 1) * (endY - startY + 1);
}