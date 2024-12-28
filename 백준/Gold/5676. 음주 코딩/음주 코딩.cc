#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class segtree{
    int n;
    vector<int> tree;

public:
    segtree(vector<int>& arr): n(arr.size()), tree(n * 4){
        make_tree(1, 0, n - 1, arr);
    }

    void update(int idx, int val){
        if(val > 0) val = 1;
        else if(val < 0) val = -1;

        update(1, 0, n - 1, idx - 1, val);
    }

    char calc(int left, int right){
        int res = calc(1, 0, n - 1, left - 1, right - 1);
        
        if(res > 0) return '+';
        else if(res < 0) return '-';
        else return '0';
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
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
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
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }

    int calc(int node, int start, int end, int left, int right){
        if(right < start || end < left) return 1;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return calc(node * 2, start, mid, left, right) * calc(node * 2 + 1, mid + 1, end, left, right);
    }
};

int main(){
    FASTIO

    int n, k;
    while(cin >> n >> k){
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;

            if(x > 0) arr[i] = 1;
            else if(x < 0) arr[i] = -1;
        }

        segtree seg(arr);

        for(int i = 0; i < k; i++){
            char cmd;
            int a, b;
            cin >> cmd >> a >> b;

            if(cmd == 'C') seg.update(a, b);
            else cout << seg.calc(a, b);
        }

        cout << "\n";
    }

    return 0;
}