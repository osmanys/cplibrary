#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
long d[MAX][26], inic[26], ini[MAX];

int main(){
	long n;
	string s;
	cin >> n;
	getline(cin, s);
	for(long i = 0; i < n; i++){
		getline(cin, s);
		inic[s[0] - 'a']++;
		ini[i] = s[0] - 'a';
		for(string::iterator it = s.begin(); it != s.end(); it++)
			d[i][*it - 'a']++;
	}
	long r = 0;
	for(long i = 0; i < n; i++){
		long j = 0;
		for(; j < 26; j++){
			if(d[i][j] > inic[j] - (ini[i] == j ? 1 : 0))
				break;
		}
		if(j == 26)
			r++;
	}
	cout << r;
	return 0;
}
