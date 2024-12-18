#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> scores(n);
    for(int i = 0; i < n; i++) cin >> scores[i];

    int answer = 0;
    for(int i = n - 2; i >= 0; i--){
        if(scores[i] >= scores[i + 1]){
            answer += scores[i] - scores[i + 1] + 1;
            scores[i] = scores[i + 1] - 1;
        }
    }

    cout << answer;

    return 0;
}