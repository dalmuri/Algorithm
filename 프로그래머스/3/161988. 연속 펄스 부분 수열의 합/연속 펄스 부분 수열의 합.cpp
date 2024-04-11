#include <vector>

using namespace std;

long long max_sum(vector<int>& arr){
    vector<long long> now_max(arr.size(), 0ll);
    now_max[0] = arr[0];
    long long result = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        now_max[i] = max(0ll, now_max[i - 1]) + arr[i];
        result = max(result, now_max[i]);
    }
    
    return result;
}

long long solution(vector<int> sequence) {
    vector<int> arr1(sequence);
    for(int i = 0; i < arr1.size(); i+= 2) arr1[i] *= -1;
    
    vector<int> arr2(sequence);
    for(int i = 1; i < arr2.size(); i+= 2) arr2[i] *= -1;
    
    return max(max_sum(arr1), max_sum(arr2));
}
