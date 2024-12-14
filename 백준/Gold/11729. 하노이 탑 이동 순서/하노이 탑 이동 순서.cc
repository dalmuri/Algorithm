#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void move_disc(int size, int start, int end){
    if(size == 0) return;

    move_disc(size - 1, start, 6 - start - end);
    cout << start << " " << end << "\n";
    move_disc(size - 1, 6 - start - end, end);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    move_disc(n, 1, 3);

    return 0;
}