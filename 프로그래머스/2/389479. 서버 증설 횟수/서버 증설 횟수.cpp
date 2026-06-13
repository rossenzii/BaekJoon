#include <string>
#include <vector>

using namespace std;
// m명 늘면 서버 1대 추가, k시간 운영 가능 (3,5)
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int pSize=players.size();
    vector<int> server(pSize, 0);
    for(int i=0; i<pSize; i++){
        int capacity=server[i]*m+(m-1);
        if(players[i]>capacity){
            int need=players[i]-capacity; // 초과된 플레이어 수
            int extra= (need+m-1)/m;// 추가로 늘릴 서버 수 - 반올림을 위해 m-1함
            //int extra = ceil(need/m)이랑 동일
            for(int j=0; j<k && i+j<pSize; j++){
                server[i+j]+=extra; // i날에 extra늘리면 i, i+1..i+k-1까지 유지됨
            }
            answer += extra;
        }
    }
    return answer;
    
    return answer;
}

