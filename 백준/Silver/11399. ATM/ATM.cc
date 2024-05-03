#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    
    int n;
    cin >> n;

    vector<int> time(n);
    for(int i = 0; i < n; i++) cin >> time[i];

    sort(time.begin(), time.end());

    for(int i = 1; i < n; i++) time[i] += time[i - 1];

    cout << accumulate(time.begin(), time.end(), 0) << endl;
    
    return 0;
}