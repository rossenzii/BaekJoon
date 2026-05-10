#include <string>
#include <vector>
using namespace std;


using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t = 0; // 경과 시간
    int count=-1; // 붕대감기 연속으로 성공한 횟수
    int attack_count=0; // 몇번째 공격인지
    int hp=health;
    int end_t=attacks[attacks.size()-1][0]; // 마지막 공격 시간

    while(t<=end_t){
      int attack_time=attacks[attack_count][0]; // 현재 공격 시간

      // 몬스터 공격 감지
      if(attack_time==t){ // 지금 공격하면
        int damage = attacks[attack_count][1];
        hp=hp-damage;

        if(hp<=0) return -1; // 죽으면 -1
        attack_time = attacks[attack_count][0];
        count=0; // 연속 붕대감기 초기화
        attack_count++; // 다음 공격으로 넘어가기
      }
      else{
        hp=min(hp+bandage[1], health);
        count++; // 연속 붕대감기 횟수 1증가
        if(count==bandage[0]){ // bandage는 [시전 시간, 초당 회복량, 추가 회복량] = [3,2,7] 3초 연속 성공하면 7추가 획듯, 초당 2 회복
          hp=min(hp+bandage[2], health);
          count=0;
        }
      }
      t++;
    }
    return hp;
}