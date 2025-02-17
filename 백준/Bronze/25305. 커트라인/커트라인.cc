#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> students(n);
    for(int i = 0; i < n; i++) cin >> students[i];

    sort(students.rbegin(), students.rend());

    cout << students[k - 1];

    return 0;
}