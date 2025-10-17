#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool check(int l, int r, vector<int>& a){
    if(r - l < 2) return true;
    if(a[l] + a[l + 1] > a[r]) return true;
    return false;
}

int calc(vector<int>& a){
    for(int len = a.size(); len >= 0; --len){
        for(int l = 0; l + len - 1 < a.size(); ++l){
            if(check(l, l + len - 1, a)){
                return len;
            }
        }
    }
    return min(2, (int)a.size());
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    cout << calc(a);

    return 0;
}