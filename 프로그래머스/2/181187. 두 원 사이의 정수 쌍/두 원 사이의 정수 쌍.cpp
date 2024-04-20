#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long r1r1 = pow(r1, 2);
    long long r2r2 = pow(r2, 2);
    
    for(int x = 0; x < r1; x++){
        long long xx = pow(x, 2);
        
        long long big = floor(sqrt(r2r2 - xx));
        long long small = ceil(sqrt(r1r1 - xx));
        answer += big - small + 1;
    }
    
    for(int x = r1; x < r2; x++){
        long long xx = pow(x, 2);
        answer += floor(sqrt(r2r2 - xx));
    }
    
    return answer * 4;
}