#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

char dict[4] = {'A', 'C', 'G', 'T'};

int c2i(char c){
    if(c == 'A') return 0;
    else if(c == 'C') return 1;
    else if(c == 'G') return 2;
    else return 3;
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<vector<char>> dna(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> dna[i][j];
        }
    }

    vector<char> answer(m);
    int hamming_dist = 0;
    for(int j = 0; j < m; j++){
        vector<int> cnt(4, 0);
        for(int i = 0; i < n; i++){
            cnt[c2i(dna[i][j])]++;
        }

        int max_idx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        answer[j] = dict[max_idx];
        if(max_idx < n) hamming_dist += accumulate(cnt.begin(), cnt.end(), -cnt[max_idx]);
    }

    for(int i = 0; i < m; i++) cout << answer[i];
    cout << "\n" << hamming_dist;

    return 0;
}