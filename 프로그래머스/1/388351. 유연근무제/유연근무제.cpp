#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i<schedules.size(); i++){
        int goal = ((schedules[i]/100 + (schedules[i]%100+10)/60)*100) + (schedules[i]%100+10)%60;
        int start=startday-1;
        int check = 1;
        
        for(int j = 0; j<timelogs[i].size(); j++){
            if(start % 7 < 5){
                if(timelogs[i][j] > goal){
                    check = 0;
                    break;
                }
            }
            start++;
        }
        
        if(check){
            answer++;
        }
    
    }
    
    return answer;
}

