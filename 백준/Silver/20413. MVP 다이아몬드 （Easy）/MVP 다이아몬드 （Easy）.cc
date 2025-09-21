#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int get_index(char c){
    switch(c){
        case 'S':
            return 1;
        case 'G':
            return 2;
        case 'P':
            return 3;
        case 'D':
            return 4;
        default:
            return 0;
    }
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> grade(5, 0);
    for(int i = 1; i < 5; ++i) cin >> grade[i];

    string mvp;
    cin >> mvp;

    int answer = 0;
    for(int i = 0, prev = 0; i < mvp.size(); ++i){
        int cost_max = mvp[i] == 'D' ? grade[get_index('D')] : grade[get_index(mvp[i]) + 1] - 1 - prev;

        prev = cost_max;
        answer += cost_max;
    }

    cout << answer;

    return 0;
}