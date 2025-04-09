#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool should_explode(int idx, vector<int>& mines, vector<bool>& exploded){
    if(exploded[idx]) return false;
    if(idx == 0 && mines.size() == 1) return true;
    if(idx == 0 && (mines[idx] >= mines[idx + 1] || exploded[idx + 1])) return true;
    if(idx == mines.size() - 1 && (mines[idx] >= mines[idx - 1] || exploded[idx - 1])) return true;
    if((mines[idx - 1] <= mines[idx] || exploded[idx - 1]) && (mines[idx] >= mines[idx + 1] || exploded[idx + 1])) return true;

    return false;
}

int explode(int idx, vector<int>& mines, vector<bool>& exploded){
    int cnt = 1;
    exploded[idx] = true;

    for(int i = idx - 1; i >= 0 && !exploded[i] && mines[i] < mines[i + 1]; --i, ++cnt) exploded[i] = true;
    for(int i = idx + 1; i < mines.size() && !exploded[i] && mines[i] < mines[i - 1]; ++i, ++cnt) exploded[i] = true;

    return cnt;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> mines(n);
    for(int i = 0; i < n; ++i) cin >> mines[i];
    
    vector<bool> exploded(n, false);
    int cnt = 0;
    vector<int> answer;
    for(int i = 0; i < n; ++i){
        if(should_explode(i, mines, exploded)){
            cnt += explode(i, mines, exploded);
            cout << i + 1 << "\n";
        }
    }

    return 0;
}