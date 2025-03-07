#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> days(n);
    for(int i = 0; i < n; i++) cin >> days[i];

    sort(days.rbegin(), days.rend());

    int answer = 0;
    for(int i = 0; i < n; i++){
        answer = max(answer, i + 2 + days[i]);
    }

    cout << answer;

    return 0;
}