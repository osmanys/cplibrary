#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	cout << (s[1] == '+' ? ((s[0] - '0') + (s[2] - '0')) : ((s[0] - '0') - (s[2] - '0')));
	return 0;
}
