#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MAX = 101;

// 운송 포인트, 운송 경로
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer=0;
    int numRobots = routes.size();
    vector<pair<int,int>> pointCoords(points.size()+1); // 특정 위치
    
    for(int i=0; i<points.size(); i++){
        int r=points[i][0];
        int c=points[i][1];
        pointCoords[i+1]={r,c}; // points[i] = {x, y}인 값 -> pointCoords[i+1] = (x, y)로 저장
    }
    
    vector<vector<pair<int,int>>> robotPaths(numRobots); //robotPaths[i]는 i번 로봇이 이동한 좌표들
    int maxTime=0;
    
    for(int i=0; i<numRobots; i++)
    {
        vector<int>& route = routes[i];
        vector<pair<int, int>> path;
        int currentR = pointCoords[route[0]].first;
        int currentC = pointCoords[route[0]].second;
        path.push_back({currentR, currentC});
        
        for(int j=1; j<route.size(); j++)
        {
            int nextR = pointCoords[route[j]].first;
            int nextC = pointCoords[route[j]].second;
            while(currentR!=nextR){
                if(currentR < nextR)
                {
                    currentR++;
                }else{
                    currentR--;
                }
                path.push_back({currentR, currentC});
            }
            while(currentC!=nextC){
                if(currentC < nextC)
                {
                    currentC++;
                }else{
                    currentC--;
                }
                path.push_back({currentR, currentC});
            }
        }
        maxTime = max(maxTime, (int)path.size());
        robotPaths[i]=path;
    }
    for(int t=0; t<maxTime; t++){
        vector<vector<int>> grid(MAX, vector<int>(MAX,0)); //(r,c)에 로봇 몇 대가 있는지 count
        for(int i=0; i<numRobots; i++)
        {
            if(t<robotPaths[i].size())
            {
                int r=robotPaths[i][t].first; //i번 로봇이 t초에 있는 위치
                int c=robotPaths[i][t].second;
                grid[r][c]++;
            }
        }
        for(int r=1; r<MAX; r++)
        {
            for(int c=1; c<MAX; c++)
            {
                if(grid[r][c]>=2)
                {
                    answer++;
                }
            }
        }
    }
    return answer;
}

