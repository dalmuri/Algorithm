#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, x;
    cin >> n >> x;

    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num < x) cout << num << " ";
    }

    return 0;
}