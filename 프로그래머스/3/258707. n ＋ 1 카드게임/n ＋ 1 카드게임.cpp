#include <string>
#include <vector>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    vector<int> order(n + 1, 0);
    for(int i = 0; i < n; i++) order[cards[i]] = i;
    
    int round = 0;
    int hand = n / 3;
    vector<bool> used(n + 1, false);
    while(true){
        round++;
        hand += 2;
        if(hand > n) break;
        bool chk = false;
        for(int i = 0; i < hand; i++){
            if(!used[cards[i]] && order[n + 1 - cards[i]] < hand && i < n / 3 && order[n + 1 - cards[i]] < n / 3){
                used[cards[i]] = true;
                used[n + 1 - cards[i]] = true;
                chk = true;
                break;
            }
        }
        
        if(!chk){
            for(int i = 0; i < hand; i++){
                if(!used[cards[i]] && order[n + 1 - cards[i]] < hand && i < n / 3 && order[n + 1 - cards[i]] >= n / 3 && coin >= 1){
                    coin -= 1;
                    used[cards[i]] = true;
                    used[n + 1 - cards[i]] = true;
                    chk = true;
                    break;
                }
            }
        }
        
        if(!chk){
            for(int i = 0; i < hand; i++){
                if(!used[cards[i]] && order[n + 1 - cards[i]] < hand && i >= n / 3 && order[n + 1 - cards[i]] >= n / 3 && coin >= 2){
                    coin -= 2;
                    used[cards[i]] = true;
                    used[n + 1 - cards[i]] = true;
                    chk = true;
                    break;
                }
            }
        }
        
        if(!chk) break;
    }
    return round;
}