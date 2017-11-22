#include <bits/stdc++.h>
 
using namespace std;
bool m[255];
 
int main() {
	int t;
	cin >> t;
	string s;bool valid;
	getline(cin, s);
	while(t--){
		getline(cin, s);
		valid = true;
		memset(m, false, sizeof m);
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(m[*it]){
				valid = false;
				break;
			}
			m[*it] = true;
		}
		cout << (valid ? "no" : "yes") << "\n";
	}
	
    return 0;
}
