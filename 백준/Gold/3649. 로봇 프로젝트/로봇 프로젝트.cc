#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int x, n;
    while(cin >> x){
        x *= 10'000'000;
        cin >> n;

        vector<int> lengths(n);
        for(int i = 0; i < n; ++i) cin >> lengths[i];

        sort(lengths.begin(), lengths.end());

        int max_diff = -1, l1, l2;
        for(int i = 0; i < n; ++i){
            auto other = lower_bound(lengths.begin() + i + 1, lengths.end(), x - lengths[i]);
            if(other != lengths.end() && lengths[i] + *other == x && *other - lengths[i] > max_diff){
                max_diff = *other - lengths[i];
                l1 = lengths[i];
                l2 = *other;
            }
        }

        if(max_diff < 0) cout << "danger\n";
        else cout << "yes " << l1 << " " << l2 << "\n";
    }

    return 0;
}