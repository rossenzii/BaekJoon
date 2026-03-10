#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

struct Student{
  string name;
  int a,b,c;
};
vector<Student> v;

void sorting(vector<Student>& v){
  sort(v.begin(), v.end(), [](const Student& s1, const Student& s2){ // 정렬할 2요소 비교
    if(s1.a != s2.a) return s1.a > s2.a; // a 점수 내림차순
    if(s1.b != s2.b) return s1.b < s2.b; // b 점수 오름차순
    if(s1.c != s2.c) return s1.c > s2.c; // c 점수 내림차순
    return s1.name < s2.name; // 이름 오름차순
  });
}


int main(){
  fastio;
  int n; cin>>n;
  for(int i=0; i<n; i++){
    Student s;
    cin>>s.name>>s.a>>s.b>>s.c;
    v.push_back(s);
  }
  sorting(v);
  for(int i=0; i<n; i++){
    cout<<v[i].name<<"\n";
  }
  return 0;
}