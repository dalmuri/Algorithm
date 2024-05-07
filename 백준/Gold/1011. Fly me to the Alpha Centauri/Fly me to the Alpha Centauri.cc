#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;

        int dist = y - x;
        int answer = 0;
        for(long long n = 1; answer == 0; n++){
            if(dist <= n * n) answer = n * 2 - 1;
            else if(n * n < dist && dist <= n * n + n) answer = n * 2;
        }

        cout << answer << "\n";
    }
    
    return 0;
}