#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int big = 0, answer = 0;
    for(int i = 0; i < n; ++i){
        int book;
        cin >> book;

        if(big > book) answer = max(answer, book);
        else big = book;
    }

    cout << answer;

    return 0;
}