#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> lis;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        auto iter = lower_bound(lis.begin(), lis.end(), num);
        if(iter == lis.end()) lis.push_back(num);
        else (*iter) = num;
    }

    cout << n - lis.size();

    return 0;
}