#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int bowls[50'001];

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0;
    for(int i = 0, bowl; i < n; ++i){
        cin >> bowl;
        answer = max(answer, ++bowls[bowl]);
    }

    cout << answer;

    return 0;
}