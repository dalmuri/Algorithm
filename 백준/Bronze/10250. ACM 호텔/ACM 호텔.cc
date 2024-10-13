#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int h, w, n;
        cin >> h >> w >> n;

        int yy = n % h;
        if(yy == 0) yy = h;

        int xx = n / h + min(n % h, 1);

        cout << yy << (xx < 10 ? "0" : "") << xx << "\n";
    }

    return 0;
}