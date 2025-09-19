#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> times(11);
    int answer = 0;
    for(int i = 0, v; i < 11; ++i){
        cin >> times[i];
        cin >> v;

        answer += v * 20;
    }

    sort(times.begin(), times.end());

    answer += times[0];
    for(int i = 1; i < 11; ++i){
        times[i] += times[i - 1];
        answer += times[i];
    }

    cout << answer;

    return 0;
}