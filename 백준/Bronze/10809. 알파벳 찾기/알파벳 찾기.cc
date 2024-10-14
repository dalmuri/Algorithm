#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string s;
    cin >> s;

    vector<int> cnt(26, -1);

    for(int i = 'a'; i <= 'z'; i++){
        cnt[i - 'a'] = s.find_first_of(i);
    }

    for(int c : cnt) cout << c << " ";

    return 0;
}