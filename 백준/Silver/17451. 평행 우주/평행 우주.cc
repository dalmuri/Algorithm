#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> velocity(n);
    for(int i = 0; i < n; ++i) cin >> velocity[i];

    long long now = 0ll;
    for(int i = n - 1; i >= 0; --i){
        if(velocity[i] >= now) now = velocity[i];
        else if(now % velocity[i]) now = (now / velocity[i] + 1) * velocity[i];
    }

    cout << now;

    return 0;
}