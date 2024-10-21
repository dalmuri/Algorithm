#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void search(int idx, vector<int>& liquid, vector<int>& answer){
    int left = idx + 1;
    int right = liquid.size() - 1;
    long long value = abs((long long)liquid[idx] + liquid[left] + liquid[right]);
    vector<int> result = {liquid[idx], liquid[left], liquid[right]};
    while(left < right){
        long long new_value = (long long)liquid[idx] + liquid[left] + liquid[right];
        if(abs(new_value) < value){
            result = {liquid[idx], liquid[left], liquid[right]};
            value = abs(new_value);
            }

        if(new_value < 0) left++;
        else if(new_value > 0) right--;
        else break;
    }

    if(abs(accumulate(result.begin(), result.end(), 0ll)) < abs(accumulate(answer.begin(), answer.end(), 0ll))) answer = result;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> liquid(n);
    for(int i = 0; i < n; i++) cin >> liquid[i];

    sort(liquid.begin(), liquid.end());
    vector<int> answer = {liquid[0], liquid[1], liquid[2]};

    for(int i = 0; i + 2 < n; i++) search(i, liquid, answer);

    for(int lq : answer) cout << lq << " ";

    return 0;
}