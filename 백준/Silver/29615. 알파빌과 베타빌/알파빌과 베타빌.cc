#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> people(n);
    for(int i = 0; i < n; ++i) cin >> people[i];

    unordered_map<int, bool> friends;
    for(int i = 0, tmp; i < m; ++i){
        cin >> tmp;
        friends[tmp] = true;
    }

    int answer = 0, f = m;
    for(int i = 0; i < m; ++i){
        if(!friends[people[i]]){
            for(; f < n; ++f){
                if(friends[people[f]]){
                    answer++;
                    swap(people[i], people[f]);
                }
            }
        }
    }

    cout << answer;

    return 0;
}