#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int b, c, d;
    cin >> b >> c >> d;

    vector<int> burgers(b);
    for(int i = 0; i < b; ++i) cin >> burgers[i];

    vector<int> sides(c);
    for(int i = 0; i < c; ++i) cin >> sides[i];

    vector<int> drinks(d);
    for(int i = 0; i < d; ++i) cin >> drinks[i];

    sort(burgers.begin(), burgers.end());
    sort(sides.begin(), sides.end());
    sort(drinks.begin(), drinks.end());

    int sets = min({b, c, d});

    long long answer = accumulate(burgers.begin(), burgers.end(), 0ll) + accumulate(sides.begin(), sides.end(), 0ll) + accumulate(drinks.begin(), drinks.end(), 0ll);
    cout << answer << "\n";

    answer = answer * 9 / 10;
    answer += accumulate(burgers.begin(), burgers.begin() + b - sets, 0ll) / 10;
    answer += accumulate(sides.begin(), sides.begin() + c - sets, 0ll) / 10;
    answer += accumulate(drinks.begin(), drinks.begin() + d - sets, 0ll) / 10;
    cout << answer;

    return 0;
}