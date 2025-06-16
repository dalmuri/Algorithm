#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string answer(n * 2, 'Z');
        int start = n, end = n;
        for(int i = 0; i < n; ++i){
            char card;
            cin >> card;

            if(card <= answer[start]) answer[--start] = card;
            else answer[end++] = card;
        }
        cout << answer.substr(start, end - start) << "\n";
    }

    return 0;
}