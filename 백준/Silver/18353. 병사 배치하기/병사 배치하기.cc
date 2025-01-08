#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> soldiers(n);
    for(int i = 0; i < n; i++) cin >> soldiers[i];

    reverse(soldiers.begin(), soldiers.end());

    vector<int> lis;
    for(int soldier : soldiers){
        auto iter = lower_bound(lis.begin(), lis.end(), soldier);
        if(iter == lis.end()) lis.push_back(soldier);
        else *iter = soldier;
    }

    cout << n - lis.size();

    return 0;
}