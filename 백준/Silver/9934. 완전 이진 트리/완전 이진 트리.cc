#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int k;
vector<int> inorder;
vector<vector<int>> answer;

void calc(int start, int end, int level){
    int mid = (start + end) / 2;

    answer[level].push_back(inorder[mid]);
    if(level == k) return;
    calc(start, mid - 1, level + 1);
    calc(mid + 1, end, level + 1);
}

int main(){
    FASTIO

    cin >> k;

    const int n = (1 << k) - 1;
    inorder = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> inorder[i];
    
    answer = vector<vector<int>>(k + 1);
    calc(0, n - 1, 1);

    for(int i = 1; i <= k; i++){
        for(int num : answer[i]){
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}