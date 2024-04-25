#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> to_binary(long long num, int& depth){
    vector<int> result;
    while(num > 0ll){
        result.push_back(num & 1);
        num >>= 1;
    }
    
    int l = result.size();
    long long cnt = 0ll;
    depth = 0;
    while(l > 0){
        if(!(l & 1)) cnt += pow(2ll, depth);
        l >>= 1;
        depth += 1;
    }
    
    vector<int> zeros(cnt, 0);
    result.insert(result.end(), zeros.begin(), zeros.end());
    
    reverse(result.begin(), result.end());
    return result;
}

bool able(int start, int end, int depth, vector<int>& tree){
    if(depth == 1) return true;
    
    int mid = (start + end) / 2;
    if(tree[mid] == 0){
        return accumulate(tree.begin() + start, tree.begin() + end + 1, 0) == 0;
    }
    
    return able(start, mid - 1, depth - 1, tree) && able(mid + 1, end, depth - 1, tree);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(long long num : numbers){
        int depth;
        vector<int> tree = to_binary(num, depth);
        answer.push_back(able(0, tree.size() - 1, depth, tree) ? 1 : 0);
    }
    return answer;
}