#include <string>
#include <iostream>
#include <vector>
#include <cmath>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class segtree{
    int n;
    vector<long long> tree;
public:
    segtree(int n, vector<long long>& numbers){
        this->n = n;
        int height = ceil(log2(n));
        int size = 1 << (height + 1);
        tree = vector<long long>(size);

        make(1, 0, n - 1, numbers);
    }

    void make(int node, int start, int end, vector<long long>& numbers){
        if(start == end){
            tree[node] = numbers[start];
            return;
        }

        int mid = (start + end) / 2;
        make(node * 2, start, mid, numbers);
        make(node * 2 + 1, mid + 1, end, numbers);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int idx, long long val){
        update(1, 0, n - 1, idx, val);
    }

    long long get(int left, int right){
        return get(1, 0, n - 1, left, right);
    }

private:
    void update(int node, int start, int end, int idx, long long val){
        if(idx < start || idx > end) return;
        if(start == end){
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        if(idx <= mid) update(node * 2, start, mid, idx, val);
        else update(node * 2 + 1, mid + 1, end, idx, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long get(int node, int start, int end, int left, int right){
        if(right < start || left > end) return 0;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
    }
};

int main(){
    FASTIO

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> numbers(n);
    for(int i = 0; i < n; i++) cin >> numbers[i];

    segtree seg = segtree(n, numbers);

    for(int i = 0; i < m + k; i++){
        int a;
        long long b, c;
        cin >> a >> b >> c;

        if(a == 1){
            seg.update(b - 1, c);
        }
        else{
            cout << seg.get(b - 1, c - 1) << "\n";
        }
    }

    return 0;
}