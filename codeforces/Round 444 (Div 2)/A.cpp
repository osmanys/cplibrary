#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	int c = 0;
	int sz = s.size();
	for(int i = sz - 1; i >= 0; i--){
		if(s[i] == '0')
			c++;
		else if(c > 5){
			cout << "yes";
			return 0;
		}
	}
	cout << "no";
	return 0;
}
