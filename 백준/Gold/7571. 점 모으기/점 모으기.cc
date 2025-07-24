#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> x(m), y(m);
    for(int i = 0; i < m; ++i) cin >> x[i] >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int midx = (m & 1) ? x[m / 2] : (x[m / 2 - 1] + x[m / 2]) / 2;
    int midy = (m & 1) ? y[m / 2] : (y[m / 2 - 1] + y[m / 2]) / 2;

    int answer = 0;
    for(int i = 0; i < m; ++i){
        answer += abs(x[i] - midx) + abs(y[i] - midy);
    }

    cout << answer;

    return 0;
}