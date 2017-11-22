#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	cout << ((s[0] == 'S' && s[n - 1] == 'F') ? "YES" : "NO");
	return 0;
}
