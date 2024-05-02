#include <string>
#include <vector>

using namespace std;

int alphabet(char c){
    return min(c - 'A', 26 - (c - 'A'));
}

int solution(string name){
    int answer = 0;
    for(char c : name) answer += alphabet(c);
    
    int len = name.size();
    int move = len - 1;
    for(int i = 0; i < name.size(); i++){
        int next_i = i + 1;
        while(next_i < len && name[next_i] == 'A') next_i++;
        move = min(move, i + (len - next_i) + min(i, len - next_i));
        // O_____iAAAAAAAAn_____        O:원점  i:i번째  n:next_i번째
        // i번째와 next_i번째 사이에는 A만 있다고 가정. 이 A가 가장 많은 경우가 최소 이동 횟수.
        // i + i + (len - next_i) = 원점에서 오른쪽으로 이동해 i로 갔다가 왼쪽으로 이동해 n으로 이동.
        // (len - next_i) + (len - next_i) + i = 원점에서 왼쪽으로 이동해 n으로 갔다가 오른쪽으로 이동해 i로 이동.
        // 위 두 경우 중 적게 이동한 것을 선택.
    }
    return answer + move;
}