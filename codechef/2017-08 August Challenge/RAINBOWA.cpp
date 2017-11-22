#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t, n, b, d, i;
	int c[10];
	bool up, valid;
	cin >> t;
	while(t--){
		cin >> n;
		b = 0;
		memset(c, 0, sizeof c);
		up = true;
		valid = true;
		for(i = 0; i < n; i++){
			cin >> d;
			if(d < 1 || d > 7)
				valid = false;
			if(up){
				if(d == b || d == b + 1){
					c[d - 1]++;
					b = d;
				}
				else if(b == 7 && d == 6)
					up = false;
				else
					valid = false;
			}
			if(!up){
				if(d == b || d == b - 1){
					c[d - 1]--;
					b = d;
				}
				else
					valid = false;
			}
		}
		cout << ((!valid || c[0] || c[1] || c[2] || c[3] || c[4] || c[5]) ? "no\n" : "yes\n");
	}
	
    return 0;
}
