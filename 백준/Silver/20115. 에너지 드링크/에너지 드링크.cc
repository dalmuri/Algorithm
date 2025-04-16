#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> drinks(n);
    for(int i = 0; i < n; ++i) cin >> drinks[i];

    iter_swap(max_element(drinks.begin(), drinks.end()), drinks.begin());

    cout << accumulate(drinks.begin() + 1, drinks.end(), (double)drinks.front(), [](double acc, int e){
        return acc + (double)e / 2.0;
    });

    return 0;
}