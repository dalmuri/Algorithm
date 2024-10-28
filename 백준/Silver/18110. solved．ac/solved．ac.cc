#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> scores(n);
    for(int i = 0; i < n; i++) cin >> scores[i];

    sort(scores.begin(), scores.end());
    int to_delete = round((float)n * 0.15);

    int sum = accumulate(scores.begin() + to_delete, scores.end() - to_delete, 0);

    if(n == 0) cout << "0";
    else cout << (int)round((float)sum / (n - 2 * to_delete));

    return 0;
}