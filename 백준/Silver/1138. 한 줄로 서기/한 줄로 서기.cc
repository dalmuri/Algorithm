#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> people(n + 1);
    for(int i = 1; i <= n; i++) cin >> people[i];

    vector<int> answer;
    for(int i = n; i > 0; i--) answer.insert(answer.begin() + people[i], i);

    for(int i = 0; i < n; i++) cout << answer[i] << " ";

    return 0;
}