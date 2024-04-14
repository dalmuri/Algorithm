#include <string>
#include <vector>

using namespace std;

double get_area(vector<int> &range, vector<int> &graph){
    int x_start = range[0];
    int x_end = graph.size() - 1 + range[1];
    if(x_end < x_start) return -1;
    
    double area = 0;
    
    for(int x = x_start; x < x_end; x++){
        area += ((double)graph[x] + graph[x+1]) / 2;
    }
    
    return area;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> graph(1, k);
    while(k != 1){
        if(k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
        
        graph.push_back(k);
    }
    
    for(vector<int> range : ranges){
        answer.push_back(get_area(range, graph));
    }
    
    
    return answer;
}