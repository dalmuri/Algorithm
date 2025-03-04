#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int width, height, n;
    cin >> width >> height >> n;

    vector<int> horizontal = {0, width};
    vector<int> vertical = {0, height};
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        if(a == 1) horizontal.push_back(b);
        else vertical.push_back(b);
    }

    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());

    int max_width = 0, max_height = 0;
    for(int i = 1; i < horizontal.size(); i++) max_width = max(max_width, horizontal[i] - horizontal[i - 1]);
    for(int i = 1; i < vertical.size(); i++) max_height = max(max_height, vertical[i] - vertical[i - 1]);

    cout << max_width * max_height;

    return 0;
}