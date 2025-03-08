#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> people(n);
    for(int i = 0; i < n; i++) cin >> people[i];

    sort(people.rbegin(), people.rend());

    long long tip = 0;
    for(int i = 0; i < n; i++) tip += max(0, people[i] - i);

    cout << tip;

    return 0;
}