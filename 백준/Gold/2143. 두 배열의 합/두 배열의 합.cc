#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t, n, m;
    cin >> t >> n;

    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    cin >> m;
    
    vector<int> b(m + 1, 0);
    for(int i = 1; i <= m; i++) cin >> b[i];

    // prefix sum
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 1; i <= m; i++) b[i] += b[i - 1];

    map<int, int> a_sum, b_sum;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            a_sum[a[j] - a[i]]++;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j <= m; j++){
            b_sum[b[j] - b[i]]++;
        }
    }

    long long answer = 0;
    for(auto iter = a_sum.begin(); iter != a_sum.end(); iter++){
        answer += (long long)(*iter).second * b_sum[t - (*iter).first];
    }

    cout << answer;

    return 0;
}