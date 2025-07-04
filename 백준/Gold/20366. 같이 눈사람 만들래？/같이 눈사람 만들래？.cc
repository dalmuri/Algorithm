#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct snowman{
    int h, i, j;

    bool operator<(const snowman& other) const{
        return h < other.h;
    }

    bool able(const snowman& other) const{
        if(i == other.i || i == other.j || j == other.i || j == other.j) return false;
        return true;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> snows(n);
    for(int i = 0; i < n; ++i) cin >> snows[i];

    vector<snowman> snowmans(n * (n - 1) / 2);
    for(int i = 0, idx = 0; i + 1 < n; ++i){
        for(int j = i + 1; j < n; ++j){
            snowmans[idx++] = {snows[i] + snows[j], i, j};
        }
    }

    sort(snowmans.begin(), snowmans.end());

    int answer = 2'000'000'000;
    for(int i = 0; i + 1 < snowmans.size(); ++i){
        int j = i + 1;
        for(; j < snowmans.size() && !snowmans[i].able(snowmans[j]); ++j);

        if(j < snowmans.size()) answer = min(answer, snowmans[j].h - snowmans[i].h);
    }

    cout << answer;

    return 0;
}