#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    string chairs;
    cin >> chairs;

    vector<bool> can_use(n + 1, true);
    bool continuous = false;
    int answer = 0;
    for(int i = 0; i < chairs.size(); i++){
        if(chairs[i] == 'L'){
            if(continuous) 
                continuous = false;
            else{
                can_use[i + 1] = false;
                continuous = true;
            }
        }

        if(can_use[i]){
            can_use[i] = false;
            answer++;
        }
        else if(can_use[i + 1]){
            can_use[i + 1] = false;
            answer++;
        }
    }

    cout << answer;

    return 0;
}