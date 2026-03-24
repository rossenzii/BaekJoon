#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
using namespace std;

string changeWord(string word, vector<vector<int>> spoiler_ranges){
  string maskedWord = word;
  for(int i=0; i<spoiler_ranges.size(); i++){ // [0,3] [23,28]
    for(int j=spoiler_ranges[i][0]; j<=spoiler_ranges[i][1]; j++){
      if(j>=0 && j<maskedWord.size() && maskedWord[j]!=' '){
        maskedWord[j]='A';
      }
    }
  }
  return maskedWord;
}



int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    set<string> sets;
    string maskedWords = changeWord(message, spoiler_ranges);
    stringstream ss(maskedWords);
    string word;
    while(ss>>word){
      sets.insert(word);
    }
    ss.clear(); // 내부 EOF 상태임 -> 다시 ss>>word하려면 작동 안 함 -> 따라서 초기화해야 함
    ss.str(message); // stringstream 안에 있는 문자열을 message로 바꾸기
    while(ss >> word) {
    if (sets.count(word) == 0) { // 이 단어가 set에 없으면
        ++answer;
        sets.insert(word);
    }
}

    return answer;
}
