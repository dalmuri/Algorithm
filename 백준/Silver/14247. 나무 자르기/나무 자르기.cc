#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> trees(n);
    for(int i = 0; i < n; ++i) cin >> trees[i].second;
    for(int i = 0; i < n; ++i) cin >> trees[i].first;

    sort(trees.begin(), trees.end());

    long long answer = 0ll;
    for(int i = 0; i < n; ++i){
        answer += trees[i].second + trees[i].first * i;
    }

    cout << answer;

    return 0;
}