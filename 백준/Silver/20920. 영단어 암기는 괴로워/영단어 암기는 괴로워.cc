#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    map<string, int> dictionary;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;

        if(str.size() < m) continue;
        dictionary[str]++;
    }

    using psi = pair<string, int>;
    vector<psi> words;
    for(auto iter = dictionary.begin(); iter != dictionary.end(); iter++) words.push_back(*iter);
    
    sort(words.begin(), words.end(), [](psi a, psi b){
        if(a.second != b.second) return a.second > b.second;
        if(a.first.size() != b.first.size()) return a.first.size() > b.first.size();
        return a.first < b.first;
    });

    for(int i = 0; i < words.size(); i++) cout << words[i].first << "\n";

    return 0;
}