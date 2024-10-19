#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class member{
public:
    int age;
    string name;

    member(int age, string name){
        this->age = age;
        this->name = name;
    }

    bool operator<(const member& b) const{
        return this->age < b.age;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<member> judge;
    for(int i = 0; i < n; i++){
        int age;
        string name;
        cin >> age >> name;
        judge.push_back(member(age, name));
    }

    stable_sort(judge.begin(), judge.end());

    for(member m : judge){
        cout << m.age << " " << m.name << "\n";
    }

    return 0;
}