#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int j, n;
        cin >> j >> n;

        vector<int> boxes(n);
        for(int i = 0; i < n; ++i){
            int r, c;
            cin >> r >> c;

            boxes[i] = r * c;
        }

        sort(boxes.rbegin(), boxes.rend());

        int answer = 0;
        for(int i = 0; i < n && j > 0; ++i){
            j -= boxes[i];
            ++answer;
        }

        cout << answer << "\n";
    }

    return 0;
}