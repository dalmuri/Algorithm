#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> people(n);
    for(int i = 0; i < n; ++i) cin >> people[i];

    sort(people.begin(), people.end());

    int l = 0, r = n - 1, answer = 0;
    while(l < r){
        if(people[l] + people[r] >= m) answer++, l++, r--;
        else l++;
    }

    cout << answer;

    return 0;
}