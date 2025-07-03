#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    cout << fixed;
    cout.precision(2);

    int n, k;
    cin >> n >> k;

    vector<double> scores(n);
    for(int i = 0; i < n; ++i) cin >> scores[i];

    sort(scores.begin(), scores.end());

    double sum = accumulate(scores.begin() + k, scores.end() - k, 0.0);

    cout << sum / (n - k * 2) + 0.000000001<< "\n"; 
    cout << (sum + scores[k] * k + scores[n - 1 - k] * k) / n + 0.000000001;

    return 0;
}