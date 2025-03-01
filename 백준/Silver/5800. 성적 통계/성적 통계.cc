#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int k;
    cin >> k;
    for(int c = 1; c <= k; c++){
        int n;
        cin >> n;

        vector<int> scores(n);
        for(int i = 0; i < n; i++) cin >> scores[i];

        sort(scores.rbegin(), scores.rend());

        int diff = 0;
        for(int i = 0; i + 1 < n; i++){
            diff = max(diff, scores[i] - scores[i + 1]);
        }

        cout << "Class " << c << "\n";
        cout << "Max " << scores.front() << ", Min " << scores.back() << ", Largest gap " << diff << "\n";
    }

    return 0;
}