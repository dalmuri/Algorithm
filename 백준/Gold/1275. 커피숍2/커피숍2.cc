#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class segtree{
    int n;
    vector<long long> tree;

public:
    segtree(vector<int>& arr) : n(arr.size()), tree(vector<long long>(n * 4)){
        init(1, 0, n - 1, arr);
    }

    void update(int idx, int val){
        update(1, 0, n - 1, idx - 1, val);
    }

    long long calc(int left, int right){
        return calc(1, 0, n - 1, left - 1, right - 1);
    }

private:
    void init(int node, int start, int end, vector<int>& arr){
        if(start == end){
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        init(node * 2, start, mid, arr);
        init(node * 2 + 1, mid + 1, end, arr);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int node, int start, int end, int idx, int val){
        if(idx < start || end < idx) return;
        if(start == end){
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long calc(int node, int start, int end, int left, int right){
        if(right < start || end < left) return 0ll;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return calc(node * 2, start, mid, left, right) + calc(node * 2 + 1, mid + 1, end, left, right);
    }
};

int main(){
    FASTIO

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    segtree seg(arr);

    for(int i = 0; i < q; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if(x > y) swap(x, y);
        cout << seg.calc(x, y) << "\n";
        seg.update(a, b);
    }

    return 0;
}