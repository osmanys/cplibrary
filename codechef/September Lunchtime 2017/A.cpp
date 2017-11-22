#include <bits/stdc++.h>
#define MAX 7
 
using namespace std;
long d[MAX];
 
int main() {
	long t, n;string s;
	cin >> t;
	while(t--){
		memset(d, 0, sizeof d);
		cin >> n;
		getline(cin, s);
		for(long i = 0; i < n; i++){
			getline(cin, s);
			if(s == "cakewalk")
				d[0]++;
			else if(s == "simple")
				d[1]++;
			else if(s == "easy")
				d[2]++;
			else if(s == "easy-medium")
				d[3]++;
			else if(s == "medium")
				d[4]++;
			else if(s == "medium-hard")
				d[5]++;
			else if(s == "hard")
				d[6]++;
		}
		cout << (d[0] && d[1] && d[2] && (d[3] || d[4]) && (d[5] || d[6])? "Yes" : "No") << "\n";
	}
    return 0;
}
