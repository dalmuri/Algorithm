#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int min = 1'000'000;
    int max = -1'000'000;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num < min) min = num;
        if(num > max) max = num;
    }

    cout << min << " " << max;

    return 0;
}