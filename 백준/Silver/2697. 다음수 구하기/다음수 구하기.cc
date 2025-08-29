#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        string num;
        cin >> num;

        if(next_permutation(num.begin(), num.end())) cout << num << "\n";
        else cout << "BIGGEST\n";
    }

    return 0;
}