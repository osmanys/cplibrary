#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long long u, v;
	cin >> t;
	while(t--){
		cin >> u >> v;
		cout << ((u + v) * (u + v + 1) / 2 + u + 1) << endl;
	}	
	return 0;
}
