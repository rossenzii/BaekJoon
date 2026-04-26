#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int record[86400001];
int limitR, limitL = 987654321;
string from, to;
int main(){
  int n; cin>>n;
  for(int i=0; i<n; i++){
    cin>>from>>to;
    istringstream ss(from);
    string buffer = "";
    vector<string> v;
    while(getline(ss,buffer,':')){
      v.push_back(buffer);
    }
    istringstream ss2(to);
    while(getline(ss2,buffer,':')){
      v.push_back(buffer);
    }
    int l = stoi(v[0])*3600000 + stoi(v[1])*60000 + stoi(v[2].substr(0, v[2].find('.')))*1000+stoi(v[2].substr(v[2].find('.')+1, v[2].size()));
    int r = stoi(v[3]) * 3600000 + stoi(v[4]) * 60000 + stoi(v[5].substr(0, v[5].find('.'))) * 1000 + stoi(v[5].substr(v[5].find('.') + 1, v[5].size()));
		record[l]++;
    record[r]--;

    limitR=max(limitR,r);
    limitL=min(limitL,l);
  }
  int total=0;
  int answer=0;
  for(int i=limitL; i<=limitR; i++){
    total+=record[i];
    answer = max(answer, total);
  }
  cout<<answer;

}