#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    set<int> to_del;
    for(int i = 0; i < n; i++){
        cin >> lines[i].first >> lines[i].second;
        to_del.insert(lines[i].first);
    }

    sort(lines.begin(), lines.end());

    vector<int> seq;
    vector<int> idxs(n);
    for(int i = 0; i < n; i++){
        auto iter = lower_bound(seq.begin(), seq.end(), lines[i].second);
        idxs[i] = iter - seq.begin();
        if(iter == seq.end()) seq.push_back(lines[i].second);
        else *iter = lines[i].second;
    }

    int idx = seq.size() - 1;
    for(int i = n - 1; i >= 0; i--){
        if(idxs[i] == idx){
            to_del.erase(lines[i].first);
            idx--;
        }
    }

    cout << n - seq.size() << "\n";
    for(auto iter = to_del.begin(); iter != to_del.end(); iter++){
        cout << *iter << "\n";
    }

    return 0;
}