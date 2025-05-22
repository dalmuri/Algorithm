#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void Flip(string& str){
    while(str.back() == '0') str.pop_back();

    reverse(str.begin(), str.end());
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<string> numbers(n);
    for(int i = 0; i < n; ++i){
        cin >> numbers[i];
        Flip(numbers[i]);
    }

    sort(numbers.begin(), numbers.end(), [](string a, string b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for(int i = 0; i < n; ++i) cout << numbers[i] << "\n";

    return 0;
}