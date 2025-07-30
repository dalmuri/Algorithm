#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 1'000'000'001;

    int n;
    cin >> n;

    vector<int> answer(n, 0);
    int lowest;
    cin >> lowest;
    for(int i = 1, num; i < n; ++i){
        cin >> num;
        lowest = min(lowest, num);

        answer[i] = max(answer[i - 1], num - lowest);
    }

    for(int i = 0; i < n; ++i) cout << answer[i] << " ";

    return 0;
}