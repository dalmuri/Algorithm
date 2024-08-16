#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = (long long)*max_element(times.begin(), times.end()) * n;
    long long answer = right;
    while(left <= right){
        long long mid = (left + right) / 2;
        long long sum = accumulate(times.begin(), times.end(), 0ll, [&](long long acc, long long now){ return acc + mid / now;});
        if(sum >= n){
            right = mid - 1;
            answer = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return answer;
}