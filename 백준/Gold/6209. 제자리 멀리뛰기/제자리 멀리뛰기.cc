#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int d, n, m;
bool check(int hop, vector<int>& stones){
    int count = 0;
    for(int i = 1, now = 0; i < n + 2; ++i){
        if(stones[i] - stones[now] < hop) count++;
        else now = i;
    }

    return count <= m;
}

int main(){
    FASTIO

    cin >> d >> n >> m;

    vector<int> stones(n + 2, 0);
    for(int i = 1; i <= n; ++i) cin >> stones[i];
    stones[n + 1] = d;
    sort(stones.begin() + 1, stones.end() - 1);

    int left = 0, right = d, answer = d;
    while(left <= right){
        int mid = (left + right) / 2;

        if(check(mid, stones)){
            answer = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << answer;

    return 0;
}