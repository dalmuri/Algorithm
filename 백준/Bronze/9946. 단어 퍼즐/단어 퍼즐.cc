#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    for(int t = 1; 1; ++t){
        string word1, word2;
        cin >> word1 >> word2;
        if(word1 == "END" && word2 == "END") break;

        cout << "Case " << t;
        if(word1.size() != word2.size()){
            cout << ": different\n";
            continue;
        }

        vector<int> alphabets(26, 0);
        int check = 0;
        for(int i = 0; i < word1.size(); ++i){
            if(++alphabets[word1[i] - 'a'] == 1) ++check;
        }
        for(int i = 0; i < word2.size(); ++i){
            if(--alphabets[word2[i] - 'a'] == 0) --check;
        }

        if(check == 0) cout << ": same\n";
        else cout << ": different\n";
    }

    return 0;
}