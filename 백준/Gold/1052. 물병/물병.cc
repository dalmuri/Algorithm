#include <iostream>
#include <string>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    FASTIO;
    int n, k;
    cin >> n >> k;

    vector<int> binary;
    int num_bottles = 0;
    while(n > 0){
        binary.push_back(n & 1);
        num_bottles += n & 1;
        n >>= 1;
    }

    int answer = 0;
    bool buying = false;
    for(int i = 0; i < binary.size(); i++){
        if(buying){
            if(binary[i] == 0){
                binary[i] = 1;
                buying = false;
            }
            else num_bottles--;
        }

        if(num_bottles <= k) break;

        if(!buying && binary[i] == 1){
            buying = true;
            answer += 1 << i;
        }
    }

    cout << answer << endl;
    
    return 0;
}