#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    for(int t = 1; 1; ++t){
        string word1, word2;
        cin >> word1 >> word2;
        if(word1 == "END" && word2 == "END") break;

        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        cout << "Case " << t;
        if(word1 == word2) cout << ": same\n";
        else cout << ": different\n";
    }

    return 0;
}