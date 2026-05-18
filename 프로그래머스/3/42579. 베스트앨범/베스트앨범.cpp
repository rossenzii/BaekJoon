#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 장르별 횟수
    map<string, int> music;
    // 장르별로 무슨 노래가 몇번 저장됐는지
    map<string, map<int, int>> musicList;
    for(int i=0; i<genres.size(); i++){
      music[genres[i]] += plays[i];
      musicList[genres[i]][i]=plays[i];
    }
    while(music.size()>0){
      string genre="";
      int max=0;
      for(auto mu:music){
        if(max<mu.second){
          max=mu.second;
          genre=mu.first;
        }
      }
      // 2번 반복 (2곡 넣음)
      for(int i=0; i<2; i++){
        int val=0, ind=-1;
        for(auto ml : musicList[genre]){
          if(val<ml.second){
            val=ml.second;
            ind=ml.first;
          }
        }
        // 노래가 0~1곡이면 반복문 탈출
        if(ind==-1) break;
        answer.push_back(ind);
        musicList[genre].erase(ind);
      }
      music.erase(genre);
    }

    return answer;
}