#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct delivery{
    int from, to, box;

    bool operator<(const delivery& other) const {
        if(to != other.to) return to < other.to;
        return from < other.from;
    }
};

int main(){
    FASTIO

    int n, c, m;
    cin >> n >> c >> m;

    vector<delivery> deliveries(m);
    for(int i = 0; i < m; i++){
        cin >> deliveries[i].from >> deliveries[i].to >> deliveries[i].box;
    }

    sort(deliveries.begin(), deliveries.end());

    int answer = 0;
    vector<int> capacity(n + 1, c);
    for(auto [from, to, box] : deliveries){
        int min_cap = c;
        for(int i = from; i < to; i++) min_cap = min({min_cap, capacity[i], box});
        for(int i = from; i < to; i++) capacity[i] -= min_cap;

        answer += min_cap;
    }

    cout << answer;

    return 0;
}