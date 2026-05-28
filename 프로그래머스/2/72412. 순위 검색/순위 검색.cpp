#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

map<string, vector<int>> scores;

void storeScore(vector<vector<string>> &tmp, int score){
    string c1,c2,c3,c4;
    for(int i=0; i<2; i++){
        c1=tmp[0][i];
        for(int j=0; j<2; j++){
            c2=tmp[1][j];
            for(int k=0; k<2; k++){
                c3=tmp[2][k];
                for(int l=0; l<2; l++){
                    c4=tmp[3][l];
                    scores[c1+c2+c3+c4].push_back(score); // 16 종류 저장
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(string s:info){
        stringstream ss(s);
        string a,b,c,d; int score;
        ss >> a >> b >> c >>d >>score;
        vector<vector<string>> newInfo={
            {a,"-"},
            {b,"-"},
            {c,"-"},
            {d,"-"}
        };
        storeScore(newInfo, score);
    }
    for(auto &sc:scores){
        sort(sc.second.begin(), sc.second.end());
    }
    for(string q : query){
        stringstream ss(q);
        string a,b,c,d,tmp; int queryScore;
        ss >> a >> tmp >> b >> tmp >> c >> tmp >> d >> queryScore;
        string key=a+b+c+d;
        vector<int> &v=scores[key];
        int cnt=v.end()-lower_bound(v.begin(), v.end(), queryScore);
        answer.push_back(cnt);
    }
    return answer;
}