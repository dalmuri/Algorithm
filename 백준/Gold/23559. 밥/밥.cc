#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, x, answer = 0;
    cin >> n >> x;

    vector<tuple<int, int, int>> menu;
    for(int i = 0, a, b; i < n; ++i){
        cin >> a >> b;

        if(a <= b){
            answer += b;
            x -= 1000;
        }
        else{
            menu.push_back({a - b, a, b});
        }
    }

    sort(menu.rbegin(), menu.rend());

    int cnt5000 = (x - menu.size() * 1000) / 4000;
    for(int i = 0; i < menu.size(); ++i){
        if(i < cnt5000) answer += get<1>(menu[i]);
        else answer += get<2>(menu[i]);
    }

    cout << answer;

    return 0;
}