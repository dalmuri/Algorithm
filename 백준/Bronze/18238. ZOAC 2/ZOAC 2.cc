#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    cin >> str;

    int now = 0, answer = 0;
    for(int i = 0; i < str.size(); ++i){
        int next = str[i] - 'A';
        answer += min(abs(next - now), 26 - abs(next - now));
        now = next;
    }

    cout << answer;

    return 0;
}