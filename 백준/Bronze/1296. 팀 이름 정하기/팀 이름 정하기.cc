#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int yondu_love[4];

void count_love(string& team, int* love){
    for(int i = 0; i < team.size(); ++i){
        switch (team[i]){
        case 'L':
            ++love[0];
            break;
        case 'O':
            ++love[1];
            break;
        case 'V':
            ++love[2];
            break;
        case 'E':
            ++love[3];
            break;
        }
    }
}

int get_score(string& team){
    int love[4] = {0, 0, 0, 0};
    copy(yondu_love, yondu_love + 4, love);
    
    count_love(team, love);

    int result = 1;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            result *= love[i] + love[j];
            result %= 100;
        }
    }

    return result;
}

int main(){
    FASTIO

    string yondu;
    cin >> yondu;

    count_love(yondu, yondu_love);

    int n;
    cin >> n;

    vector<pair<int, string>> teams(n);
    for(int i = 0; i < n; ++i){
        string team;
        cin >> team;

        teams[i] = {get_score(team), team};
    }

    cout << max_element(teams.begin(), teams.end(), [](pair<int, string> a, pair<int, string> b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    })->second;

    return 0;
}