#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        string num = to_string(n);
        bool is_pal = true;
        for(int i = 0; i * 2 < num.size(); i++){
            if(num[i] != num[num.size() - 1 - i]){
                is_pal = false;
                break;
            }
        }

        cout << (is_pal ? "yes\n" : "no\n");
    }

    return 0;
}