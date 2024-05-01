#include <iostream>
#include <string>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    FASTIO;

    long long w, h, f, c, x1, y1, x2, y2;
    cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

    long long folded = f * 2 <= w ? f : w - f;

    cout << w * h - max(0ll, (min(x2, folded) - x1) * (y2 - y1) * (c + 1) * 2) - max(0ll, (x2 - max(x1, folded)) * (y2 - y1) * (c + 1)) << endl;
    return 0;
}