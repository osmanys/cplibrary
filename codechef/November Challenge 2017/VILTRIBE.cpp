#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t, st;
	long a, b, c;
	string s;
	cin >> t;
	getline(cin, s);
	while(t--){
		getline(cin, s);
		a = 0;
		b = 0;
		st = 0;
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(*it == 'A'){
				if(st == 1)
					a += c;
				else
					st = 1;
				c = 0;
				a++;
			}
			else if(*it == 'B'){
				if(st == 2)
					b += c;
				else
					st = 2;
				c = 0;
				b++;				
			}
			else
				c++;
		}
		cout << a << " " << b << "\n";
	}
    return 0;
}
