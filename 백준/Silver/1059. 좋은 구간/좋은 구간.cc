#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int l, n;
    cin >> l;

    vector<int> s(l);
    for(int i = 0; i < l; i++) cin >> s[i];
    cin >> n;

    sort(s.begin(), s.end());

    int right = upper_bound(s.begin(), s.end(), n) - s.begin();
    int left = right - 1;

    int answer = 0;
    if(right < l && s[left] < n){
        answer = (n - s[left]) * (s[right] - n) - 1;
    }

    cout << answer;

    return 0;
}