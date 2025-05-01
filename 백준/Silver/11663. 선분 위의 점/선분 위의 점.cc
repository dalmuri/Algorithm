#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> points(n);
    for(int i = 0; i < n; ++i) cin >> points[i];

    sort(points.begin(), points.end());

    for(int i = 0; i < m; ++i){
        int start, end;
        cin >> start >> end;

        auto l = lower_bound(points.begin(), points.end(), start);
        auto r = upper_bound(points.begin(), points.end(), end);

        cout << r - l << "\n";
    }

    return 0;
}