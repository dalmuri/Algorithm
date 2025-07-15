#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> points(m);
    for(int i = 0, tmp; i < m; ++i) cin >> points[i] >> tmp;

    sort(points.rbegin(), points.rend());

    int answer = 0;
    for(int i = 0; i < m - 1; ++i){
        if(points[i] < n) answer += n - points[i];
    }

    cout << answer;

    return 0;
}