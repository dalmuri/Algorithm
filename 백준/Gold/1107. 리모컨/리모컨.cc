#include <iostream>
#include <string>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<bool> buttons(10, true);

bool can_move(int ch){
    if(ch == 0) return buttons[0];
    while(ch){
        if(!buttons[ch % 10]) return false;
        ch /= 10;
    }
    return true;
}

int main() {
    FASTIO;

    int channel, n;
    cin >> channel;
    cin >> n;
    int broken = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        buttons[tmp] = false;
        broken++;
    }

    int answer = abs(channel - 100);

    if(broken < 10){
        for(int c = channel; c >= 0 && channel - c < answer; c--){
            if(can_move(c)){
                answer = min(answer, (int)to_string(c).size() + channel - c);
                break;
            }
        }

        for(int c = channel; c - channel < answer; c++){
            if(can_move(c)){
                answer = min(answer, (int)to_string(c).size() + c - channel);
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}