#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> toppings(n);
    for(int i = 0; i < n; ++i) cin >> toppings[i];

    sort(toppings.rbegin(), toppings.rend());

    for(int i = 1; i < n; ++i) toppings[i] += toppings[i - 1];

    int calories_per_won = c / a;
    for(int i = 0; i < n; ++i){
        int now = (c + toppings[i]) / (a + b * (i + 1));
        if(calories_per_won > now) break;
        
        calories_per_won = now;
    }

    cout << calories_per_won;

    return 0;
}