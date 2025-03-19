#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> vec(3);

int check(int a, int b, int c){
	int maxNum = max(max(a, b), c);
	if (a + b > c && maxNum == c)
		return a + b + c;
	else if (b + c > a && maxNum == a)
	    return a + b + c;
	
	else if (a + c > b && maxNum == b)
	    return a + b + c;

	return -1;
}

int main(){
	FASTIO

	int n;
	cin >> n;
	
	int answer = -1;

	for( int i = 0; i < n; i ++){
		int length;
		cin >> length;

		if (i < 3){
			vec[i] = length;
			continue;
		}

		int num1 = check(length, vec[1], vec[2]);
		int num2 = check(vec[0], length, vec[2]);
		int num3 = check(vec[0], vec[1], length);
		int maxSize = max(num3, max(num1, num2));
		if (maxSize > answer){
			if (maxSize == num1) vec[0] = length;
			else if (maxSize == num2) vec[1] = length;
			else if (maxSize == num3) vec[2] = length;
			answer = maxSize;
		}
	}

	if (n == 3) cout << check(vec[0], vec[1], vec[2]);
	else cout << answer;

	return 0;
}