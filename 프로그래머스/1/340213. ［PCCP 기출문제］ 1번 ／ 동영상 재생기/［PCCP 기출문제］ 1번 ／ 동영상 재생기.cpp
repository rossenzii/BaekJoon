#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long intToMinute(string str){
    int find=str.find(':');
    return stoi(str.substr(0,find))*60+stoi(str.substr(find+1));
}



string solution(string video_len, string pos, string op_start, string op_end,vector<string> commands){
    string answer="";
    long long len = intToMinute(video_len);
    long long start=intToMinute(op_start);
    long long end = intToMinute(op_end);
    long long now=intToMinute(pos);
    
    for(auto a:commands){
        if(now>=start && now<=end) now=end;
        if(a=="prev"){
            now-=10;
            if(now<0) now=0;
        }else {
            now+=10;
            if(now>len) now=len;
        }
        if(now>=start && now<=end) now=end;
    }
    int m=now/60;
    int s=now%60;
    string mS=to_string(m);
    string sS=to_string(s);
    answer+= (m<10?"0"+mS:mS);
    answer+=":";
    answer+= (s<10?"0"+sS:sS);
    return answer;
                 
}