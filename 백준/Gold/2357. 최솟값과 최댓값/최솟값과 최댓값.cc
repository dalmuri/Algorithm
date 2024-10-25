#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int MAX = 1'000'000'001;
int MIN = 0;

struct seg{
    int min, max;
};

class segtree{
    int n;
    vector<seg> tree;

public:
    segtree(vector<int>& nums){
        n = nums.size();
        tree = vector<seg>(4 * n);

        make(1, 0, n - 1, nums);
    }

    void make(int node, int start, int end, vector<int>& nums){
        if(start == end){
            tree[node].max = nums[start];
            tree[node].min = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        make(node * 2, start, mid, nums);
        make(node * 2 + 1, mid + 1, end, nums);
        tree[node].max = max(tree[node * 2].max, tree[node * 2 + 1].max);
        tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);
    }

    int get_max(int node, int start, int end, int left, int right){
        if(right < start || end < left) return MIN;
        if(left <= start && end <= right) return tree[node].max;

        int mid = (start + end) / 2;
        return max(get_max(node * 2, start, mid, left, right), get_max(node * 2 + 1, mid + 1, end, left, right));
    }

    int get_min(int node, int start, int end, int left, int right){
        if(right < start || end < left) return MAX;
        if(left <= start && end <= right) return tree[node].min;

        int mid = (start + end) / 2;
        return min(get_min(node * 2, start, mid, left, right), get_min(node * 2 + 1, mid + 1, end, left, right));
    }
};

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    segtree s = segtree(nums);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << s.get_min(1, 0, n - 1, a - 1, b - 1) << " " << s.get_max(1, 0, n - 1, a - 1, b - 1) << "\n";
    }

    return 0;
}