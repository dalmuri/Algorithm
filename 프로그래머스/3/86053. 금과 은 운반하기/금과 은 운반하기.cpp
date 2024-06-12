#include <string>
#include <vector>
#include <climits>

using namespace std;

bool can_transport(long long time, int a, int b, int n, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t){
    long long total = 0ll;
    long long total_gold = 0ll;
    long long total_silver = 0ll;
    for(int i = 0; i < n; i++){
        long long cnt = time / (2ll * t[i]);
        if(time % (2ll * t[i]) >= t[i]) cnt++;
        
        long long weight = min(cnt * w[i], (long long) g[i] + s[i]);
        total += weight;
        total_gold += min(weight, (long long) g[i]);
        total_silver += min(weight, (long long) s[i]);
    }
    
    if(total >= a + b && total_gold >= a && total_silver >= b) return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    int n = g.size(); // 도시 개수
    
    long long left = 0;
    long long right = 1e9 * 2ll * 1e5 * 2ll;
    long long answer = right;
    
    while(left <= right){
        long long mid = (left + right) / 2ll;
        
        if(can_transport(mid, a, b, n, g, s, w, t)){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return answer;
}