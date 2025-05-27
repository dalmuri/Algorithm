#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, s, r;
    cin >> n >> s >> r;

    vector<bool> wants(n + 1, false);
    for(int i = 0; i < s; ++i){
        int num;
        cin >> num;

        wants[num] = true;
    }

    vector<bool> extra(n + 2, false);
    for(int i = 0; i < r; ++i){
        int num;
        cin >> num;

        if(wants[num]) wants[num] = false;
        else extra[num] = true;
    }

    int answer = 0;
    for(int i = 1; i <= n; ++i){
        if(!wants[i]) continue;

        if(extra[i - 1]) continue;
        if(extra[i + 1]){
            extra[i + 1] = false;
            continue;
        }

        answer++;
    }

    cout << answer;

    return 0;
}