#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;
    
    int min_package = 1001;
    int min_piece = 1001;
    for(int i = 0; i < m; i++){
        int package, piece;
        cin >> package >> piece;

        min_package = min(min_package, package);
        min_piece = min(min_piece, piece);
    }

    int answer = min({min_piece * n, min_package * (n / 6 + min(1, n % 6)), min_package * (n / 6) + min_piece * (n % 6)});
    cout << answer;

    return 0;
}