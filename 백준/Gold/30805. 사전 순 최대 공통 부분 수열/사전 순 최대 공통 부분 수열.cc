#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    using pii = pair<int, int>;

    int n, m;
    cin >> n;

    vector<pii> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    cin >> m;

    vector<pii> b(m);
    for(int i = 0; i < m; ++i){
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a.begin(), a.end(), [](pii x, pii y){
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });

    sort(b.begin(), b.end(), [](pii x, pii y){
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });

    vector<int> answer;
    for(int i = 0, j = 0, _a = -1, _b = -1; i < n && j < m;){
        if(a[i].first == b[j].first){
            if(_a < a[i].second && _b < b[j].second){
                answer.push_back(a[i].first);
                _a = a[i++].second;
                _b = b[j++].second;
            }
            else{
                if(a[i].second < _a) i++;
                if(b[j].second < _b) j++;
            }
        }
        else if(a[i].first > b[j].first) i++;
        else j++;
    }

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); ++i) cout << answer[i] << " ";

    return 0;
}