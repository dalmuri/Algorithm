#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class segtree{
    int n;
    vector<long long> tree;

public:
    segtree(int n): n(n), tree(n * 4, 0ll){}

    void update(int idx, int val){
        update(1, 0, n - 1, idx - 1, val);
    }

    long long calc(int left, int right){
        return calc(1, 0, n - 1, left - 1, right - 1);
    }

private:
    void update(int node, int start, int end, int idx, long long val){
        if(idx < start || end < idx) return;
        if(start == end){
            tree[node] += val;
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long calc(int node, int start, int end, int left, int right){
        if(end < left || right < start) return 0ll;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return calc(node * 2, start, mid, left, right) + calc(node * 2 + 1, mid + 1, end, left, right);
    }
};

int main(){
    FASTIO

    int n, q;
    cin >> n >> q;

    segtree seg(n);

    for(int i = 0; i < q; i++){
        int cmd, p, x;
        cin >> cmd >> p >> x;

        if(cmd == 1) seg.update(p, x);
        else cout << seg.calc(p, x) << "\n";
    }

    return 0;
}