#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> root;

struct info{
    int dist, a, b;

    bool operator<(const info& other) const{
        return this->dist < other.dist;
    }
};

int find_root(int num){
    if(root[num] == -1) return num;
    return root[num] = find_root(root[num]);
}

void union_root(int a, int b){
    int root_a = find_root(a);
    int root_b = find_root(b);

    if(root_a == root_b) return;
    root[max(root_a, root_b)] = min(root_a, root_b);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    root = vector<int>(n, -1);
    vector<pair<int, int>> xs(n);
    vector<pair<int, int>> ys(n);
    vector<pair<int, int>> zs(n);
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;

        xs[i] = {x, i};
        ys[i] = {y, i};
        zs[i] = {z, i};
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(zs.begin(), zs.end());

    vector<info> infos(3 * n - 3);
    for(int i = 0; i + 1 < n; i++){
        infos[i * 3] = {xs[i + 1].first - xs[i].first, xs[i].second, xs[i + 1].second};
        infos[i * 3 + 1] = {ys[i + 1].first - ys[i].first, ys[i].second, ys[i + 1].second};
        infos[i * 3 + 2] = {zs[i + 1].first - zs[i].first, zs[i].second, zs[i + 1].second};
    }

    sort(infos.begin(), infos.end());

    long long answer = 0ll;
    for(int i = 0; i < infos.size(); i++){
        int a = infos[i].a;
        int b = infos[i].b;

        if(find_root(a) != find_root(b)){
            union_root(a, b);
            answer += infos[i].dist;
        }
    }

    cout << answer;

    return 0;
}