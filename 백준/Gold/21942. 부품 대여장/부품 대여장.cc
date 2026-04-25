#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

struct infor{
  string date;
  string time;
  string product;
  string name;
};

// 월 누적 일수 (윤년 없음)
int prefixDays[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int toMinute(const string &date, const string &time){
  int month = (date[5]-'0')*10 + (date[6]-'0');
  int day   = (date[8]-'0')*10 + (date[9]-'0');
  int hour  = (time[0]-'0')*10 + (time[1]-'0');
  int min   = (time[3]-'0')*10 + (time[4]-'0');

  int totalDays = prefixDays[month] + day;

  return totalDays * 1440 + hour * 60 + min;
}

unordered_map<string, long long> solve(vector<infor>& information, int limitMin, int f){
  unordered_map<string, int> rentTime;
  unordered_map<string, long long> fine;

  for(auto& info : information){
    string key = info.product + "#" + info.name;
    int curTime = toMinute(info.date, info.time);

    if(rentTime.find(key) == rentTime.end()){
      rentTime[key] = curTime;
    } else {
      int rentAt = rentTime[key];
      int diff = curTime - (rentAt + limitMin);

      if(diff > 0){
        fine[info.name] += (long long)diff * f;
      }
      rentTime.erase(key);
    }
  }
  return fine;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, f;
  string dateTime;
  cin >> n >> dateTime >> f;

  vector<infor> inforVector(n);
  for(int i=0; i<n; i++){
    cin >> inforVector[i].date >> inforVector[i].time 
        >> inforVector[i].product >> inforVector[i].name;
  }

  int slash = dateTime.find('/');
  int limitDay  = stoi(dateTime.substr(0, slash));
  int limitHour = stoi(dateTime.substr(slash+1, 2));
  int limitMin  = stoi(dateTime.substr(slash+4, 2));

  int totalLimitMin = limitDay * 1440 + limitHour * 60 + limitMin;

  auto result = solve(inforVector, totalLimitMin, f);

  if(result.empty()){
    cout << -1 << '\n';
  } else {
    // 출력은 이름 기준 정렬 필요
    map<string, long long> sorted(result.begin(), result.end());
    for(auto &p : sorted){
      cout << p.first << " " << p.second << '\n';
    }
  }

  return 0;
}