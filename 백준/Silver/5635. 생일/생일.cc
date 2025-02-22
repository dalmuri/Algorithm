#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct student{
    string name;
    int y, m, d;

    bool operator<(const student& other) const{
        if(y != other.y) return y < other.y;
        if(m != other.m) return m < other.m;
        return d < other.d;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<student> students(n);
    for(int i = 0; i < n; i++) cin >> students[i].name >> students[i].d >> students[i].m >> students[i].y;

    sort(students.begin(), students.end());

    cout << students.back().name << "\n" << students.front().name;

    return 0;
}