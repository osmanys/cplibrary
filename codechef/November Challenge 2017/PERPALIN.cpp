#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	string s;
	long n, p;
	cin >> t;
	while(t--){
		cin >> n >> p;
		s = "";
		if(p < 3)
			cout << "impossible\n";
		else{
			for(long i = 0; i < p / 2; i++)
				s += i & 1 ? 'b' : 'a';
			if(p & 1)
				s += ((p / 2) & 1) ? 'b' : 'a';
			for(long i = 0; i < p / 2; i++)
				s += ((p / 2) + i) & 1 ? 'a' : 'b';				
			for(long i = 0; i < n; i += p)
				cout << s;
			cout << "\n";
		}
	}
    return 0;
}
