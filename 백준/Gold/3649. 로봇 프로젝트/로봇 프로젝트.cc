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

        int max_diff = -1, l1, l2, left = 0, right = n - 1;
        while(left < right){
            if(lengths[left] + lengths[right] < x) left++;
            else if(lengths[left] + lengths[right] > x) right--;
            else{
                if(lengths[right] - lengths[left] > max_diff){
                    max_diff = lengths[right] - lengths[left];
                    l1 = lengths[left];
                    l2 = lengths[right];
                }
                left++;
                right--;
            }
        }

        if(max_diff < 0) cout << "danger\n";
        else cout << "yes " << l1 << " " << l2 << "\n";
    }

    return 0;
}