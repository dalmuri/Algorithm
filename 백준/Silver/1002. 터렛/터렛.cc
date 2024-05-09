#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        
        int answer;
        if(dist > r1 + r2) answer = 0;
        else if(dist == r1 + r2) answer = 1;
        else if(dist == 0 && r1 == r2) answer = -1;
        else if(dist > abs(r1 - r2)) answer = 2;
        else if(dist == abs(r1 - r2)) answer = 1;
        else answer = 0;
        
        cout << answer << "\n";
    }

    return 0;
}