#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, c, h;
	long p, d;
	cin >> t;
	while(t--){
		cin >> n >> p;
		c = 0, h = 0;
		for(int i = 0; i < n; i++){
			cin >> d;
			if(d <= p / 10)
				h++;
			else if(d >= p / 2)
				c++;
		}
		cout << ((h == 2 && c == 1) ? "yes" : "no") << "\n";
	}	
	return 0;
}
