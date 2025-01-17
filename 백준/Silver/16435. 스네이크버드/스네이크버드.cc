#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, l;
    cin >> n >> l;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) cin >> heights[i];

    sort(heights.begin(), heights.end());

    for(int i = 0; i < n; i++){
        if(heights[i] <= l){
            l++;
        }
        else break;
    }

    cout << l;

    return 0;
}