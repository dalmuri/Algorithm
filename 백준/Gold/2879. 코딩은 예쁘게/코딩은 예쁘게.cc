#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> count(n);
    for(int i = 0; i < n; ++i) cin >> count[i];
    for(int i = 0, tmp; i < n; ++i){
        cin >> tmp;
        count[i] -= tmp;
    }
    
    int answer = 0;
    for(int i = 0; i < n; ++i){
        if(count[i] == 0) continue;

        answer += abs(count[i]);
        for(int j = i + 1, tab = count[i]; j < n; ++j){
            if(count[j] == 0 || (count[i] < 0) != (count[j] < 0)) break;

            if(abs(tab) > abs(count[j])) tab = count[j];
            count[j] -= tab;
        }
    }

    cout << answer;

    return 0;
}