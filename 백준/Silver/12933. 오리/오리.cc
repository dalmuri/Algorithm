#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    map<char, int> to_int = {{'q', 0}, {'u', 1}, {'a', 2}, {'c', 3}, {'k', 4}};

    string sound;
    cin >> sound;

    int count = 0, answer = 0;
    vector<int> ducks(4, 0);

    for(int i = 0; i < sound.size(); ++i){
        int now = to_int[sound[i]];
        if(now == 0){
            ducks[now]++;
            answer = max(answer, ++count);
        }
        else{
            if(ducks[now - 1] <= 0){
                answer = -1;
                break;
            }

            ducks[now - 1]--;

            if(now == 4) count--;
            else ducks[now]++;
        }
    }

    if(accumulate(ducks.begin(), ducks.end(), 0) != 0) answer = -1;

    cout << answer;

    return 0;
}