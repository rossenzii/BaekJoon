#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();  // 원본 길이로 초기화
    
    // 길이 1이면 압축 불가
    if(s.size() == 1) return 1;
    
    for (int n=1; n<=s.size()/2; n++){
        string compress="";
        string prev = s.substr(0,n);
        int count=1;
        for(int j=n; j<s.size(); j+=n){
            string next=s.substr(j,n);
            if(prev==next){
              count++;
            }
            else{
                if(count>1) compress+=to_string(count);
                compress+=prev;
                prev=next;
                count=1;
            }
        }
        if(count>1) compress+=to_string(count);
        compress+=prev;
        answer = min(answer, (int)compress.size());
    }
    return answer;
}