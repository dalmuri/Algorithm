#include <string>
#include <iostream>
#include <set>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    set<int> mods;
    int num;
    for(int i = 0; i < 10; i++){
        cin >> num;
        mods.insert(num % 42);
    }

    cout << mods.size();

    return 0;
}