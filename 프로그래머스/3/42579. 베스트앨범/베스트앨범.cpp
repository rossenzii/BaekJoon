#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int,int>>> songs; // 장르별 곡 목록
    int sizeG=genres.size();
    // 1. 데이터 정리
    for(int i=0; i<sizeG; i++){
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i],i}); // 장르, 재생 횟수, 고유 번호
    }
    // 2. 장르별 총 재생수 내림차순
    vector<pair<int, string>> order; // 재생 수, 장르
    for(auto&[genre, cnt] : total){
        order.push_back({cnt,genre});
    }
    sort(order.begin(), order.end(), greater<>()); // 내림차순

    // 3. 각 장르별로 상위 2개
    for(auto&[cnt, genre] : order){
        sort(songs[genre].begin(), songs[genre].end(), [](auto& a, auto& b){
            if(a.first!=b.first) return a.first>b.first;
            return a.second<b.second;
        });
        int take=min(2, (int)songs[genre].size());
        for(int i=0; i<take; i++){
            answer.push_back(songs[genre][i].second);
        }
    }
    
    return answer;
}