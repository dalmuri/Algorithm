#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int mod = 1'000'000'007;

class segtree{
    int n;
    vector<int> tree;

public:
    segtree(vector<int>& arr){
        n = arr.size();
        tree = vector<int>(n * 4);

        make_tree(1, 0, n - 1, arr);
    }

    void make_tree(int node, int start, int end, vector<int>& arr){
        if(start == end){
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        make_tree(node * 2, start, mid, arr);
        make_tree(node * 2 + 1, mid + 1, end, arr);
        tree[node] = ((long long)tree[node * 2] * tree[node * 2 + 1]) % mod;
    }

    void update(int idx, int val){
        update(1, 0, n - 1, idx, val);
    }

    int calc(int left, int right){
        return calc(1, 0, n - 1, left, right);
    }

private:
    void update(int node, int start, int end, int idx, int val){
        if(idx < start || end < idx) return;
        if(start == end){
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = ((long long)tree[node * 2] * tree[node * 2 + 1]) % mod;
    }

    int calc(int node, int start, int end, int left, int right){
        if(end < left || right < start) return 1;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return ((long long)calc(node * 2, start, mid, left, right) * calc(node * 2 + 1, mid + 1, end, left, right)) % mod;
    }
};

int main(){
    FASTIO

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    segtree st(arr);

    for(int i = 0; i < m + k; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1) st.update(b - 1, c);
        else cout << st.calc(b - 1, c - 1) << "\n";
    }

    return 0;
}