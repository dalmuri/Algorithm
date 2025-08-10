#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    string a, b;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;

        int to_zero = 0, to_one = 0;
        for(int j = 0; j < a.size(); ++j){
            if(a[j] != b[j]){
                if(b[j] == '0') to_zero++;
                else to_one++;
            }
        }

        cout << max(to_zero, to_one) << "\n";
    }

    return 0;
}