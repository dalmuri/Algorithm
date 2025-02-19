#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct country{
    int num, gold, silver, bronze;

    bool operator<(const country& other) const{
        if(gold != other.gold) return gold < other.gold;
        if(silver != other.silver) return silver < other.silver;
        return bronze < other.bronze;
    }

    bool same(const country& other) const{
        return gold == other.gold && silver == other.silver && bronze == other.bronze;
    }
};

int get_rank(int k, vector<country>& countries){
    if(countries[0].num == k) return 1;

    int res = 1;
    for(int i = 1; i < countries.size(); i++){
        if(!countries[i - 1].same(countries[i])) res = i + 1;

        if(countries[i].num == k) break;
    }

    return res;
}

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<country> countries(n);
    for(int i = 0; i < n; i++) cin >> countries[i].num >> countries[i].gold >> countries[i].silver >> countries[i].bronze;
    
    sort(countries.rbegin(), countries.rend());

    cout << get_rank(k, countries);

    return 0;
}