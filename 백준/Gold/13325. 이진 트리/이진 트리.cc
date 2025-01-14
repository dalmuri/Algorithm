#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int get_max_dist(int node, const vector<int>& edges){
    if(node << 1 >= edges.size()) return 0;

    return max(get_max_dist(node << 1, edges) + edges[node << 1], get_max_dist((node << 1) + 1, edges) + edges[(node << 1) + 1]);
}

int get_increasing_count(int node, int dist, int& inc, const int max_dist, const vector<int>& edges){
    if(node << 1 >= edges.size()) return max_dist - dist;

    int cnt1 = get_increasing_count(node << 1, dist + edges[node << 1], inc, max_dist, edges);
    int cnt2 = get_increasing_count((node << 1) + 1, dist + edges[(node << 1) + 1], inc, max_dist, edges);

    inc += max(cnt1, cnt2) - min(cnt1, cnt2);
    return min(cnt1, cnt2); 
}

int main(){
    FASTIO

    int k;
    cin >> k;
    vector<int> edges(1 << (k + 1), 0);

    for(int i = 2; i < edges.size(); i++) cin >> edges[i];

    int max_dist = get_max_dist(1, edges);
    int to_increase = 0;

    to_increase += get_increasing_count(1, 0, to_increase, max_dist, edges);

    cout << to_increase + accumulate(edges.begin() + 2, edges.end(), 0);

    return 0;
}