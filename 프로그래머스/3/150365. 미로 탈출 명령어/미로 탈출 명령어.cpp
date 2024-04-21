#include <string>
#include <vector>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int down = 0;
    int left = 0;
    int right = 0;
    int up = 0;
    
    if(r > x) down = r - x;
    else up = x - r;
    
    if(c > y) right = c - y;
    else left = y - c;
    
    k -= down + left + right + up;
    if(k < 0 || (k & 1) == 1) return "impossible";
    
    int down_over = min(n - max(r, x), k / 2);
    k -= down_over * 2;
    int left_over = min(min(c, y) - 1, k / 2);
    k -= left_over * 2;
    string rl = "";
    for(int i = 0; i < k / 2; i++) rl += "rl";
    
    return string(down + down_over, 'd') + string(left + left_over, 'l') + rl + string(right + left_over, 'r') + string(up + down_over, 'u');
}