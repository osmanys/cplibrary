#include <bits/stdc++.h>
#define CLASS 7

using namespace std;
int d[CLASS];

int main(){
	int n; string s;
	cin >> n;
	getline(cin, s);
	for(int i = 0; i < n; i++){
		getline(cin, s);
		for(int i = 0; i < CLASS; i++)
			d[i] += (s[i] == '1');
	}
	sort(d, d + CLASS);
	cout << d[CLASS - 1];
	return 0;
}
