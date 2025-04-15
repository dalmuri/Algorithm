#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b, n;
    cin >> a >> b >> n;

    int answer = abs(a - b);
    for(int i = 0; i < n; ++i){
        int ch;
        cin >> ch;

        answer = min(answer, abs(ch - b) + 1);
    }

    cout << answer;

    return 0;
}