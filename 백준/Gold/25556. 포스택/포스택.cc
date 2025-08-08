#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int get_idx(int num, vector<int>& stks){
    int idx = -1, now = 0;
    for(int i = 0; i < stks.size(); ++i){
        if(now < stks[i] && stks[i] < num){
            idx = i;
            now = stks[i];
        }
        else if(stks[i] == 0 && idx == -1){
            return i;
        }
    }

    return idx;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> stks(4, 0);
    bool answer = true;
    for(int i = 0, num; i < n; ++i){
        cin >> num;

        int idx = get_idx(num, stks);
        if(idx < 0){
            answer = false;
            break;
        }
        stks[idx] = num;
    }

    cout << (answer ? "YES" : "NO");

    return 0;
}