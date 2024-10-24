#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> board(3);
    vector<int> mx(3, 0);
    vector<int> mn(3, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> board[j];
        }

        vector<int> tmp(mx);
        mx[0] = board[0] + max(tmp[0], tmp[1]);
        mx[1] = board[1] + max({tmp[0], tmp[1], tmp[2]});
        mx[2] = board[2] + max(tmp[1], tmp[2]);

        tmp = mn;
        mn[0] = board[0] + min(tmp[0], tmp[1]);
        mn[1] = board[1] + min({tmp[0], tmp[1], tmp[2]});
        mn[2] = board[2] + min(tmp[1], tmp[2]);
    }

    cout << max({mx[0], mx[1], mx[2]}) << " " << min({mn[0], mn[1], mn[2]});

    return 0;
}