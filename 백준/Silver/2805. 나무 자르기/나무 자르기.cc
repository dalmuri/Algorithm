#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> trees(n);
    for(int i = 0; i < n; i++){
        cin >> trees[i];
    }

    long long left = 0;
    long long right = *max_element(trees.begin(), trees.end());
    long long answer = left;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long sum = accumulate(trees.begin(), trees.end(), 0ll, [&mid](long long acc, long long tree){
            return acc + max(0ll, tree - mid);
        });

        if(sum >= m){
            left = mid + 1;
            answer = mid;
        }
        else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}