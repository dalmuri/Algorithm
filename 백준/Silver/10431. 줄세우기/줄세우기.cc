#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int p;
    cin >> p;
    while(p--){
        int t;
        cin >> t;

        list<int> heights;
        int answer = 0;
        for(int i = 0; i < 20; i++){
            int height;
            cin >> height;

            int idx = 0;
            auto pos = heights.end();
            for(auto iter = heights.begin(); iter != heights.end(); ++iter, ++idx){
                if(height < *iter){
                    pos = iter;
                    break;
                }
            }

            answer += heights.size() - idx;
            if(pos != heights.end()) heights.emplace(pos, height);
            else heights.push_back(height);
        }
        
        cout << t << " " << answer << "\n";
    }

    return 0;
}