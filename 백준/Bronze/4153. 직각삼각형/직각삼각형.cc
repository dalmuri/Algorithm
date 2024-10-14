#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void swap(int& n1, int& n2){
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

int main(){
    FASTIO

    while(1){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0) break;

        if(a > c) swap(a, c);
        if(b > c) swap(b, c);

        if(a * a + b * b == c * c) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}