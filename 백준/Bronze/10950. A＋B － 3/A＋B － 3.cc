#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        cout << a + b << "\n";
    }

    return 0;
}