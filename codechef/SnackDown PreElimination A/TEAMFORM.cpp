#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, m, u, v;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
		}
		cout << (n & 1 ? "no" : "yes") << endl;
	}
	
	return 0;
}
