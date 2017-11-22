#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	int st = 0;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		if(*it == 'A'){
			st = 1;
		}
		else if(*it == 'C'){
			if(st == 1){
				st = 2;
				break;
			}
		}
		else
			st = 0;
	}
	cout << (st == 2 ? "Yes" : "No");
	return 0;
}
