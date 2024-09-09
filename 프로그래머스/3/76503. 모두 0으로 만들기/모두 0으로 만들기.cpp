#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

long long calc(int node, int parent, vector<long long>& weights, vector<vector<int>>& tree){
    long long result = 0ll;
    
    for(int child : tree[node]){
        if(child == parent) continue;
        
        result += calc(child, node, weights, tree);
    }
    
    if(parent == -1) return result;
    
    result += abs(weights[node]);
    weights[parent] += weights[node];
    weights[node] = 0ll;
    
    return result;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    if(accumulate(a.begin(), a.end(), 0ll) != 0ll) return -1ll;
    
    vector<vector<int>> tree(a.size(), vector<int>());
    for(vector<int> edge : edges){
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }
    
    vector<long long> weights;
    for(int weight : a) weights.push_back(weight);
    
    return calc(0, -1, weights, tree);
}