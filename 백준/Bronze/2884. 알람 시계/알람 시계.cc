#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int h, m;
    cin >> h >> m;

    m -= 45;
    if(m < 0){
        m += 60;
        h -= 1;

        if(h < 0) h += 24;
    }

    cout << h << " " << m;

    return 0;
}