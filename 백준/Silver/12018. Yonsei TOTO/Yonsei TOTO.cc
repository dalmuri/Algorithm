#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> lectures(n, 1);
    for(int i = 0; i < n; ++i){
        int p, l;
        cin >> p >> l;

        vector<int> mileages(p);
        for(int j = 0; j < p; ++j) cin >> mileages[j];

        if(p < l) continue;

        sort(mileages.rbegin(), mileages.rend());

        lectures[i] = mileages[l - 1];
    }

    sort(lectures.begin(), lectures.end());

    int answer = 0;
    for(int i = 0; i < n && m >= lectures[i]; ++i){
        m -= lectures[i];
        ++answer;
    }

    cout << answer;

    return 0;
}