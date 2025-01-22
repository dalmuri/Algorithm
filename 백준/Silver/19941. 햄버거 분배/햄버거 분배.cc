#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> people;
    vector<int> hamburgers;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'P') people.push_back(i);
        else hamburgers.push_back(i);
    }

    int h = 0, answer = 0;
    for(int p = 0; p < people.size(); p++){
        while(h < hamburgers.size() && hamburgers[h] < people[p] - k) h++;
        if(h >= hamburgers.size()) break;

        if(people[p] - k <= hamburgers[h] && hamburgers[h] <= people[p] + k){
            answer++;
            h++;
        }
    }

    cout << answer;

    return 0;
}