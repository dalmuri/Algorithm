#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct student{
    string name;
    int kor, eng, math;
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<student> students(n);
    for(int i = 0; i < n; i++){
        student tmp;
        cin >> tmp.name >> tmp.kor >> tmp.eng >> tmp.math;

        students[i] = tmp;
    }

    sort(students.begin(), students.end(), [](student a, student b){
        if(a.kor != b.kor) return a.kor > b.kor;
        if(a.eng != b.eng) return a.eng < b.eng;
        if(a.math != b.math) return a.math > b.math;
        return a.name < b.name;
    });

    for(int i = 0; i < n; i++) cout << students[i].name << "\n";

    return 0;
}