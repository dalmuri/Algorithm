#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> children(n);
    for(int i = 0; i < n; i++) cin >> children[i];
    
    vector<pair<int, int>> diff(n - 1); // (오른쪽 원생과의 키 차이, idx)
    for(int i = 0; i + 1 < n; i++) diff[i] = {children[i + 1] - children[i], i};

    sort(diff.rbegin(), diff.rend());

    vector<bool> is_right(n, false);
    for(int i = 0; i < k - 1; i++) is_right[diff[i].second] = true;
    is_right[n - 1] = true;

    int left = 0;
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(is_right[i]){
            answer += children[i] - children[left];
            left = i + 1;
        }
    }

    cout << answer;

    return 0;
}