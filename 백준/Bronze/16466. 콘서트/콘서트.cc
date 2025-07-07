#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> tickets(n);
    for(int i = 0; i < n; ++i) cin >> tickets[i];

    sort(tickets.begin(), tickets.end());

    int answer = tickets.back() + 1;
    for(int i = 0, last = 0; i < n; ++i){
        if(last + 1 < tickets[i]){
            answer = last + 1;
            break;
        }
        last = tickets[i];
    }

    cout << answer;

    return 0;
}