#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    map<string, int> books;
    int sale = 0;
    string best_seller = "";
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;

        int cnt = ++books[name];
        if(sale < cnt || (cnt == sale && name < best_seller)){
            sale = cnt;
            best_seller = name;
        }
    }

    cout << best_seller;

    return 0;
}