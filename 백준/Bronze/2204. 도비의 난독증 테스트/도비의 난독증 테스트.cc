#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string to_lower(string& word){
    string result = word;
    for(int i = 0; i < result.size(); ++i){
        if('A' <= result[i] && result[i] <= 'Z') result[i] -= 'A' - 'a';
    }

    return result;
}

int main(){
    FASTIO

    vector<pair<string, string>> words(1000);

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        for(int i = 0; i < n; ++i){
            cin >> words[i].second;
            words[i].first = to_lower(words[i].second);
        }

        cout << min_element(words.begin(), words.begin() + n)->second << "\n";
    }

    return 0;
}