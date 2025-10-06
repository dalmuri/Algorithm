#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string vote;
    cin >> vote;

    int u = 0, d = 0;
    for(int i = 0; i < vote.size(); ++i){
        if(vote[i] == 'U' || vote[i] == 'C') u++;
        else d++;
    }

    string answer = "";
    if(u > (d + 1) / 2) answer += "U";
    if(d > 0) answer += "DP";

    if(answer.empty()) answer = "C";

    cout << answer;

    return 0;
}