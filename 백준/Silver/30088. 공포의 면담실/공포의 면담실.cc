#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> times(n);
    for(int i = 0, m; i < n; ++i){
        cin >> m;

        int sum = 0;
        for(int j = 0, time; j < m; ++j){
            cin >> time;
            sum += time;
        }

        times[i] = sum;
    }

    sort(times.begin(), times.end());

    for(int i = 1; i < n; ++i) times[i] += times[i - 1];

    cout << accumulate(times.begin(), times.end(), 0ll);

    return 0;
}