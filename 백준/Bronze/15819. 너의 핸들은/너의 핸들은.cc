#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, l;
    cin >> n >> l;

    vector<string> handles(n);
    for(int i = 0; i < n; ++i) cin >> handles[i];

    sort(handles.begin(), handles.end());

    cout << handles[l - 1];

    return 0;
}