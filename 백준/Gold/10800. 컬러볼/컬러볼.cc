#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct ball{
    int size, color, idx;

    bool operator<(const ball& other) const{
        if(this->size != other.size) return this->size < other.size;
        return this->color < other.color;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<ball> balls(n);
    for(int i = 0; i < n; ++i){
        cin >> balls[i].color >> balls[i].size;
        balls[i].idx = i;
    }

    sort(balls.begin(), balls.end());

    map<int, int> color_sum;
    map<int, int> same_size;
    int sum = 0;
    vector<int> answer(n, 0);
    for(int i = 0; i < n; ++i){
        answer[balls[i].idx] = sum - color_sum[balls[i].color] - same_size[balls[i].size];

        sum += balls[i].size;
        color_sum[balls[i].color] += balls[i].size;
        same_size[balls[i].size] += balls[i].size;

        if(i > 0 && balls[i].color == balls[i - 1].color && balls[i].size == balls[i - 1].size) answer[balls[i].idx] = answer[balls[i - 1].idx];
    }

    for(int i = 0; i < n; ++i) cout << answer[i] << "\n";

    return 0;
}