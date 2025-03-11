#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    if(a.length() < b.length()) return true;
    else if(a.length() == b.length()) return a < b;
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> r_words; // 문자열들 뒤집은 vector
    for(auto word: words) {
        r_words.push_back(string(word.rbegin(), word.rend()));
    }
    
    // 이분탐색 위해 정렬
    sort(words.begin(), words.end(), cmp);
    sort(r_words.begin(), r_words.end(), cmp);
    
    for(auto query: queries) {
        bool flag = query[0] == '?';
        
        // 물음표가 앞에 있을 경우 뒤집기
        if(flag) reverse(query.begin(), query.end());
        
        string start = "", end = "";
        for(auto q: query) {
            if(q == '?') {
                start += 'a';
                end += 'z';
            }
            else {
                start += q;
                end += q;
            }
        }
        
        int count = 0;
        // 물음표가 앞에 있을 경우 문자열들 뒤집은 vector로 계산
        if(flag) count = upper_bound(r_words.begin(), r_words.end(), end, cmp)
                            - lower_bound(r_words.begin(), r_words.end(), start, cmp);
        else count = upper_bound(words.begin(), words.end(), end, cmp) 
                            - lower_bound(words.begin(), words.end(), start, cmp);
        
        answer.push_back(count);
    }
    
    return answer;
}