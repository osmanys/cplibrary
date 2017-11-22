#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	long k;
	int m, b;
	cin >> s;
	cin >> k >> b >> m;
	long result = 0, mult = 1, n = s.size();
	long temp = s[0] - '0';
	for(long i = 1; i < k; i++){
		temp = (temp * b + (s[i] - '0')) % m;
		mult = (mult * b) % m;
	}
	result += temp;
	for(long i = k; i < n; i++){
		temp -= (s[i - k] - '0') * mult;
		temp = (m + (temp * b + (s[i] - '0')) % m) % m;
		result += temp;
	}
	cout << result <<endl;
	
	return 0;
}
