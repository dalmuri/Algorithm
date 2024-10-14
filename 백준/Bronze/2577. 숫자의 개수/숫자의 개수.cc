#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b, c;
    cin >> a >> b >> c;

    string str = to_string(a * b * c);
    vector<int> cnt(10, 0);
    for(char c : str){
        cnt[c - '0']++;
    }

    for(int n : cnt) cout << n << "\n";

    return 0;
}