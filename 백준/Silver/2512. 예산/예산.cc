#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;

    vector<int> costs(n);
    for(int i = 0; i < n; i++) cin >> costs[i];

    cin >> m;

    int sum = accumulate(costs.begin(), costs.end(), 0);
    int answer = *max_element(costs.begin(), costs.end());
    if(sum > m){
        int left = 0, right = m;
        while(left <= right){
            int mid = (left + right) / 2;

            int acc = accumulate(costs.begin(), costs.end(), 0, [&mid](int ac, int e){ return ac + min(mid, e); });
            if(acc <= m){
                left = mid + 1;
                answer = mid;
            }
            else{
                right = mid - 1;
            }
        }
    }

    cout << answer;

    return 0;
}