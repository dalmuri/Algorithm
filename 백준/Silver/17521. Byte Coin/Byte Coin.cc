#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    long long w;
    cin >> n >> w;

    long long coin = 0ll;
    int prev, next;
    cin >> prev;
    for(int i = 1; i < n; ++i, prev = next){
        cin >> next;
        if(prev <= next){
            coin += w / prev;
            w %= prev;
        }
        else{
            w += coin * prev;
            coin = 0ll;
        }
    }
    w += coin * next;

    cout << w;

    return 0;
}