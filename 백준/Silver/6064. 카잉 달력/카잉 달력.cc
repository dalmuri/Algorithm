#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    FASTIO

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int last = lcm(m, n);
        int answer = -1;
        for(int i = x; i <= last; i+=m){
            if(i % n == y % n){
                answer = i;
                break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}