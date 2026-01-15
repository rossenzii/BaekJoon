#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<char> operation;
deque<long long> num;
string str;

bool oper(char c){
  return c=='*' || c=='/';
}
bool oper2(char c){
  return c=='+' || c=='-';
}

void parsing(){
  string token = "";
  for(int i = 0; i < (int)str.length(); i++){
    // 연산자면 분리 (단, i>0일 때만)
    if(i > 0 && (oper(str[i]) || oper2(str[i]))){
      num.push_back(stoll(token));
      token = "";
      operation.push_back(str[i]);
    } else {
      token += str[i];
    }
  }
  num.push_back(stoll(token));
}

long long calc(long long a, long long b, char c){
  switch(c){
    case '*': return a*b;
    case '/': return a/b; // 정수 나눗셈
    case '+': return a+b;
    case '-': return a-b;
    default:  return 0;   // 안전장치
  }
}

void solve(){
  parsing();

  if(operation.empty()){
    cout << num[0];
    return;
  }

  long long left = 0;
  long long right = (long long)num.size() - 1;

  while(!operation.empty()){
    // 마지막 연산
    if(operation.size() == 1){
      long long ans = calc(num[left], num[right], operation.front());
      cout << ans;
      return;
    }

    // 왼쪽 우선순위가 높음
    if(oper(operation.front()) && oper2(operation.back())){
      num[left+1] = calc(num[left], num[left+1], operation.front());
      left++;
      operation.pop_front();
    }
    // 오른쪽 우선순위가 높음
    else if(oper2(operation.front()) && oper(operation.back())){
      num[right-1] = calc(num[right-1], num[right], operation.back());
      right--;
      operation.pop_back();
    }
    else{
      long long tempL = calc(num[left], num[left+1], operation.front());
      long long tempR = calc(num[right-1], num[right], operation.back());

      if(tempL >= tempR){
        num[left+1] = tempL;
        left++;
        operation.pop_front();
      } else {
        num[right-1] = tempR;
        right--;
        operation.pop_back();
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> str;
  solve();
  return 0;
}