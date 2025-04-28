#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;
    
    vector<string> names(n);
    for(int i = 0; i < n; ++i) cin >> names[i];
    
    if(names[0] < names[1]){
        bool increasing = true;
        for(int i = 1; i + 1 < n; ++i){
            if(names[i] > names[i + 1]){
                increasing = false;
                break;
            }
        }
        
        if(increasing) cout << "INCREASING";
        else cout << "NEITHER";
    }
    else{
        bool decreasing = true;
        for(int i = 1; i + 1 < n; ++i){
            if(names[i] < names[i + 1]){
                decreasing = false;
                break;
            }
        }
        
        if(decreasing) cout << "DECREASING";
        else cout << "NEITHER";
    }

    return 0;
}