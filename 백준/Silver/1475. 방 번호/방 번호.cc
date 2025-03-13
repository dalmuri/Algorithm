#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string number;
    cin >> number;

    vector<int> cnt(9, 0);
    int cnt6 = 0;

    for(int i = 0; i < number.size(); i++){
        if(number[i] == '6' || number[i] == '9') cnt6++;
        else cnt[number[i] - '0']++;
    }

    cout << max(*max_element(cnt.begin(), cnt.end()), (cnt6 + 1) / 2);

    return 0;
}