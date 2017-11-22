#include <bits/stdc++.h>
#define MAX 100

using namespace std;
string d[MAX];

int main(){
	int n, j;string s;
	cin >> n;
	getline(cin, s);
	for(int i = 0; i < n; i++){
		getline(cin, s);
		d[i] = s;
		j = 0;
		for(; j < i; j++){
			if(d[j] == s)
			break;
		}
		printf(j == i ? "NO\n" : "YES\n");
	}
	return 0;
}
