#include <string>
#include <iostream>
#include <vector>
#include <cmath>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> polygon;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        polygon.push_back({x, y});
    }

    double area = 0;
    for(int i = 0; i < n; i++){
        long long x1 = polygon[i][0];
        long long y1 = polygon[i][1];

        long long x2 = polygon[(i + 1) % n][0];
        long long y2 = polygon[(i + 1) % n][1];

        area += (x1 + x2) * (y1 - y2) / 2.0;
    }

    area = abs(area);

    cout << fixed;
    cout.precision(1);
    cout << area;

    return 0;
}