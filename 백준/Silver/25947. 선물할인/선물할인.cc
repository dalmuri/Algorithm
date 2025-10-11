#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, b, a;
    cin >> n >> b >> a;

    vector<int> prices(n);
    for(int i = 0; i < n; ++i) cin >> prices[i];

    sort(prices.begin(), prices.end());

    stack<int> not_saled;
    int answer = 0;
    for(int i = 0; i < n; ++answer, ++i){
        if(prices[i] <= b){
            b -= prices[i];
            not_saled.push(prices[i]);
        }
        else if(a > 0){
            while(a > 1 && !not_saled.empty() && prices[i] / 2 > b){
                b += not_saled.top() / 2;
                not_saled.pop();
                a--;
            }

            if(prices[i] / 2 <= b){
                b -= prices[i] / 2;
                a--;
            }
            else break;
        }
        else break;
    }

    cout << answer;

    return 0;
}