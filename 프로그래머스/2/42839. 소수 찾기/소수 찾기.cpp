#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int solution(string numbers) {
    set<int> answer;
    
    vector<bool> is_prime(pow(10, numbers.size()), true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int n=2; n<is_prime.size(); n++){
        if(!is_prime[n]) continue;
        for(int i = n*n; i<is_prime.size(); i+=n){
            is_prime[i] = false;
        }
    }
    
    sort(numbers.begin(), numbers.end());
    do{
        for(int len=1; len<=numbers.size(); len++){
            int num = stoi(numbers.substr(0, len));
            if(is_prime[num]) answer.insert(num);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer.size();
}