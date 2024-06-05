#include <string>
#include <vector>

using namespace std;

long long search(int node, int parent, vector<vector<int>>& tree, vector<long long>& weights){
    long long cnt = 0;
    for(int child : tree[node]){
        if(child == parent) continue;
        
        cnt += search(child, node, tree, weights);
    }
    
    if(parent < 0) return cnt;
    
    cnt += abs(weights[node]);
    weights[parent] += weights[node];
    weights[node] = 0;
    
    return cnt;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<vector<int>> tree(a.size(), vector<int>());
    vector<long long> weights;
    for(int w : a) weights.push_back(w);
    for(vector<int> edge : edges){
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }
    
    long long answer = search(0, -1, tree, weights);
    if(weights[0] != 0) return -1ll;
    
    return answer;
}