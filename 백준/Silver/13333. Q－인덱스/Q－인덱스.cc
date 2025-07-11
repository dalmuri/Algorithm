#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> papers(n);
    for(int i = 0; i < n; ++i) cin >> papers[i];

    sort(papers.begin(), papers.end());

    int k = n;
    for(; k >= 0; --k){
        int cnt = papers.end() - lower_bound(papers.begin(), papers.end(), k);
        if(cnt >= k) break;
    }

    cout << k;

    return 0;
}