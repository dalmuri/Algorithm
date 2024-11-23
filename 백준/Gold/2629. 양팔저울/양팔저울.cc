#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;

    vector<bool> can_measure(40'501, false);
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];

    for(int weight : weights){
        vector<bool> tmp(can_measure);
        for(int i = 0; i <= 40'500; i++){
            if(can_measure[i]){
                if(i + weight <= 40500) tmp[i + weight] = true;
                if(i - weight >= 0) tmp[i - weight] = true;
                if(weight - i >= 0) tmp[weight - i] = true;
            }
        }
        tmp[weight] = true;
        can_measure = move(tmp);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int marble;
        cin >> marble;

        if(can_measure[marble]) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}