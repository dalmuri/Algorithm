#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 1'000'000'001;

class segtree{
    int n;
    vector<int> tree;

public:
    segtree(vector<int>& arr): n(arr.size()), tree(vector<int>(arr.size() * 4)){
        make_tree(1, 0, n - 1, arr);
    }

    int get_min(int left, int right){
        return calc(1, 0, n - 1, left - 1, right - 1);
    }

private:
    void make_tree(int node, int start, int end, vector<int>& arr){
        if(start == end){
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        make_tree(node * 2, start, mid, arr);
        make_tree(node * 2 + 1, mid + 1, end, arr);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    int calc(int node, int start, int end, int left, int right){
        if(end < left || right < start) return inf;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return min(calc(node * 2, start, mid, left, right), calc(node * 2 + 1, mid + 1, end, left, right));
    }
};

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    segtree root(arr);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        cout << root.get_min(a, b) << "\n";
    }

    return 0;
}