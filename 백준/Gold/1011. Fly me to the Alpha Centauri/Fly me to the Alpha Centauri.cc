#include <iostream>
#include <climits>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

using namespace std;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;

        int dist = y - x;
        ll left = 0;
        ll right = INT_MAX; // 2^31 - 1
        ll n = right;
        while(left <= right){
            ll mid = (left + right) / 2;

            if(dist <= mid * mid + mid){
                n = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        int answer = dist > n * n ? 2 * n : 2 * n - 1;

        cout << answer << "\n";
    }
    
    return 0;
}