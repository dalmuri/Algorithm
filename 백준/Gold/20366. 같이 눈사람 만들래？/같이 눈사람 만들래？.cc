#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> snows(n);
    for(int i = 0; i < n; ++i) cin >> snows[i];

    sort(snows.begin(), snows.end());

    int answer = 2'000'000'000;
    for(int i = 0; i + 1 < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int l = 0, r = n - 1, snowman = snows[i] + snows[j], min_diff = 2'000'000'000;

            while(l < r){
                if(l == i || l == j){ l++; continue; }
                if(r == i || r == j){ r--; continue; }

                int height = snows[l] + snows[r];
                if(abs(height - snowman) < min_diff){
                    min_diff = abs(height - snowman);
                }

                if(height > snowman) r--;
                else if(height < snowman) l++;
                else break;
            }

            answer = min(answer, min_diff);
        }
    }

    cout << answer;

    return 0;
}