#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    long long answer = 0ll;

    for(int i = 0; i < 3; ++i){
        int chicken = min(a, x);
        answer += chicken;
        a -= chicken;
        x -= chicken;

        int pizza = min(b, y);
        answer += pizza;
        b -= pizza;
        y -= pizza;

        int hamburger = min(c, z);
        answer += hamburger;
        c -= hamburger;
        z -= hamburger;

        auto [xx, yy, zz] = tuple{x / 3, y / 3, z / 3};
        y = xx;
        z = yy;
        x = zz;
    }

    cout << answer;

    return 0;
}