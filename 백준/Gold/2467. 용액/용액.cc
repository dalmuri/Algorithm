#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void select(vector<int>& result, int a, int b){
    if(abs(result[0] + result[1]) > abs(a + b)){
        result[0] = a;
        result[1] = b;
    }
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> liquid(n);
    for(int i = 0; i < n; i++) cin >> liquid[i];

    int l = 0;
    int r = n - 1;
    vector<int> answer = {liquid[l], liquid[r]};
    while(l < r){
        select(answer, liquid[l], liquid[r]);

        if(liquid[l] + liquid[r] < 0){
            l++;
        }
        else if(liquid[l] + liquid[r] > 0){
            r--;
        }
        else break;
    }

    cout << answer[0] << " " << answer[1];

    return 0;
}