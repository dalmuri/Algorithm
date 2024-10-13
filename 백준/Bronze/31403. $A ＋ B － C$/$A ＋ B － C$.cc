#include <string>
#include <iostream>
#include <cmath>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << "\n" << stoi(to_string(a) + to_string(b)) - c;

    return 0;
}