#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int a = 0, b = 0; a < A.size() && b < B.size(); b++){
        if(A[a] < B[b]){
            answer++;
            a++;
        }
    }
    return answer;
}