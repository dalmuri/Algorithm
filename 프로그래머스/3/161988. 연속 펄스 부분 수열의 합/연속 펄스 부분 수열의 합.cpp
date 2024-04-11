#include <vector>

using namespace std;

long long max_sum(vector<int>& seq){
    vector<long long> now_max(seq.size(), 0ll);
    now_max[0] = seq[0];
    long long result = seq[0];
    
    for(int i = 1; i < seq.size(); i++){
        now_max[i] = max(0ll, now_max[i - 1]) + seq[i];
        result = max(result, now_max[i]);
    }
    
    return result;
}

long long solution(vector<int> sequence) {
    vector<int> seq1(sequence);
    for(int i = 0; i < seq1.size(); i+= 2) seq1[i] *= -1;
    
    vector<int> seq2(sequence);
    for(int i = 1; i < seq2.size(); i+= 2) seq2[i] *= -1;
    
    return max(max_sum(seq1), max_sum(seq2));
}