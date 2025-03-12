#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> milks(n);
    for(int i = 0; i < n; i++) cin >> milks[i];

    sort(milks.rbegin(), milks.rend());

    int answer = 0;
    for(int i = 0; i < n; i+=3){
        if(i + 3 <= n) answer += accumulate(milks.begin() + i, milks.begin() + i + 2, 0);
        else for(int j = i; j < n; j++) answer += milks[j];
    }

    cout << answer;

    return 0;
}