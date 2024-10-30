#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n;
        cin >> n;

        map<string, int> clothes;
        for(int i = 0; i < n; i++){
            string name, type;
            cin >> name >> type;

            clothes[type]++;
        }

        int answer = 1;
        for(auto iter = clothes.begin(); iter != clothes.end(); iter++) answer *= (*iter).second + 1;
        answer--;

        cout << answer << "\n";
    }

    return 0;
}