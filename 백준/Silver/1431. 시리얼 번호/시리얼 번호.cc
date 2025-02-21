#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct guitar{
    string serial;
    int sum;

    bool operator<(const guitar& other) const{
        if(serial.size() != other.serial.size()) return serial.size() < other.serial.size();
        if(sum != other.sum) return sum < other.sum;
        return serial < other.serial;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<guitar> guitars(n);
    for(int i = 0; i < n; i++){
        cin >> guitars[i].serial;
        guitars[i].sum = accumulate(guitars[i].serial.begin(), guitars[i].serial.end(), 0, [](int acc, char c){
            if('0' <= c && c <= '9') return acc + c - '0';
            return acc;
        });
    }

    sort(guitars.begin(), guitars.end());

    for(int i = 0; i < n; i++) cout << guitars[i].serial << "\n";

    return 0;
}