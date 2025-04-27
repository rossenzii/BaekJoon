#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[360010]; // 최대 재생 시간


int time_to_sec(string time){
    int h=stoi(time.substr(0,2)); //인덱스 0부터 2글자 뗴오기
    int m=stoi(time.substr(3,2));
    int s=stoi(time.substr(6,2));
    return 3600*h+60*m+s;
}

string time_tostring(int t){
    string ret="";
    int h=t/3600; t%=3600;
    int m=t/60;
    int s=t%60;
    
    ret += h>=10 ? to_string(h) : ("0"+to_string(h)); //9는 09로 만들기
    ret += ":";
    ret += m>=10 ? to_string(m) : ("0"+to_string(m));
    ret += ":";
    ret += s>=10 ? to_string(s) : ("0" +to_string(s));
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int END = time_to_sec(play_time);
    int ADV = time_to_sec(adv_time);
    
    int answer = 0;
    long long sum = 0;
    
    for(string log: logs){
        int t1 = time_to_sec(log.substr(0,8)); //시작(초)
        int t2 = time_to_sec(log.substr(9)); //끝(초)
        
        arr[t1] +=1; //시청자수 +1
        arr[t2] -=1;
    }
    for(int i=0; i<END-1; i++) arr[i+1] +=arr[i]; //시간별 시청자 누적합(몇명이 시청중인지)
    for(int i=0; i<ADV; i++) sum+=arr[i]; //0~ADV초까지 시청자 수 총합 (첫번째 슬라이딩 윈도우)
    
    long long max_sum = sum;
    for(int i=ADV; i<END; i++){
        sum-=arr[i-ADV];
        sum+=arr[i];
        if(sum>max_sum){
            max_sum = sum;
            answer = i-ADV+1; // i: 현재 윈도우의 오른쪽 끝 인덱스, ADV: 슬라이딩 윈도우 크기
        }
    }
    return time_tostring(answer);
}
