#include <bits/stdc++.h>

using namespace std;

int main(){
	string e;
	cin >> e;
	cout << ((e.size() == 18 && (e[0] - 'a' >= 0) && (e[1] - 'a' >= 0) && (e[2] - 'a' >= 0) && (e[3] - 'a' >= 0) && (e[4] - 'a' >= 0) && (e[0] - 'z' <= 0) && (e[1] - 'z' <= 0) && (e[2] - 'z' <= 0) && (e[3] - 'z' <= 0) && (e[4] - 'z' <= 0) && e.substr(5) == "@hogwarts.com") ? "Yes" : "No");	
	return 0;
}
