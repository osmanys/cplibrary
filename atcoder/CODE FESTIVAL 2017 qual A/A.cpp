#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	cout << ((s.size() > 3 && s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I') ? "Yes" : "No");
	return 0;
}
