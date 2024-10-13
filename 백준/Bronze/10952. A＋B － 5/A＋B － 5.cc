#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b;

    while(1){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        cout << a + b << "\n";
    }

    return 0;
}