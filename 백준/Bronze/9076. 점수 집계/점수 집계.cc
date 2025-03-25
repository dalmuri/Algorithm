#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> scores(5);

    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < scores.size(); i++) cin >> scores[i];

        sort(scores.begin(), scores.end());

        if(scores[3] - scores[1] >= 4) cout << "KIN\n";
        else cout << scores[1] + scores[2] + scores[3] << "\n";
    }

    return 0;
}