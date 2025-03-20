#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int na, nb;
    cin >> na >> nb;

    vector<int> a(na);
    for(int i = 0; i < na; i++) cin >> a[i];

    vector<int> b(nb);
    for(int i = 0; i < nb; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ia = 0, ib = 0;
    vector<int> answer;
    while(ia < na && ib < nb){
        if(a[ia] == b[ib]){
            ia++;
            ib++;
        }
        else if(a[ia] < b[ib]){
            answer.push_back(a[ia++]);
        }
        else{
            ib++;
        }
    }
    for(; ia < na; ia++) answer.push_back(a[ia]);
    
    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++) cout << answer[i] << " ";

    return 0;
}