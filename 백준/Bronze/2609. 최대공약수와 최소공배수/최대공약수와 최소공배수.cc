#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    FASTIO

    int a, b;
    cin >> a >> b;
    
    int g = gcd(a, b);
    cout << g << "\n" << a * b / g;

    return 0;
}