#include <vector>
#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    int i;
    cin >> str;
    cin >> i;

    cout << str[i - 1];

    return 0;
}