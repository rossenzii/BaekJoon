#include <string>
#include <vector>
using namespace std;

int time_to_sec(string time){
    int hour=stoi(time.substr(0,2));
    int min=stoi(time.substr(3,2));
    int sec=stoi(time.substr(6,2));
    return hour*3600+min*60+sec;
}

string sec_to_time(int sec){

    string answer="";

    int hour=sec/3600;
    sec%=3600;

    int min=sec/60;
    sec%=60;

    answer += hour>=10 ? to_string(hour) : "0"+to_string(hour);
    answer += ":";
    answer += min>=10 ? to_string(min) : "0"+to_string(min);
    answer += ":";
    answer += sec>=10 ? to_string(sec) : "0"+to_string(sec);

    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {

    int end=time_to_sec(play_time);
    int advTime=time_to_sec(adv_time);

    vector<long long> arr(end+2,0);

    for(auto log: logs){

        int t1=time_to_sec(log.substr(0,8));
        int t2=time_to_sec(log.substr(9));

        arr[t1]+=1;
        arr[t2]-=1;
    }

    // 시청자 수
    for(int i=0; i<end; i++)
        arr[i+1]+=arr[i];

    long long sum=0;

    for(int i=0; i<advTime; i++)
        sum+=arr[i];

    long long maxSum=sum;
    int answer=0;

    for(int i=advTime; i<end; i++){

        sum-=arr[i-advTime];
        sum+=arr[i];

        if(sum>maxSum){
            maxSum=sum;
            answer=i-advTime+1;
        }
    }

    return sec_to_time(answer);
}