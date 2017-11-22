#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	int st = 0, count = 0;
	char c, b = 0;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		c = (*it);
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			cout << c;
			count = 0;
			st = 0;
		}
		else{
			count++;
			if(st == 0){
				cout << c;
				st = 1;
			}
			else if(st == 1){
				if(count == 2 && c == b){				
					cout << c;
					st = 2;
				}
				else if(count == 3){
					cout << " " << c;
					count = 1;
				}
				else				
					cout << c;
			}
			else if(st == 2){
				if(c != b){
					cout << " " << c;
					st = 1;
					count = 1;
				}
				else
					cout << c;
			}
		}
		b = c;
	}
	return 0;
}
