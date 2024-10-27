#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    scanf("%d", &n);

    vector<int> score(n);
    for(int i = 0; i < n; i++) scanf("%d", &score[i]);

    int max_score = *max_element(score.begin(), score.end());

    printf("%lf", accumulate(score.begin(), score.end(), 0.0, [&](double acc, int e){ return acc + (double)e / max_score * 100; }) / n);

    return 0;
}