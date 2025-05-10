#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int arrows[1'000'001];

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0;
    for(int i = 0; i < n; ++i){
        int balloon;
        cin >> balloon;

        if(arrows[balloon] > 0) --arrows[balloon];
        else ++answer;

        if(balloon > 1) ++arrows[balloon - 1];
    }

    cout << answer;

    return 0;
}