#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t, n, a;
	cin >> t;
	while(t--){
		cin >> n;
		a = (n + 1) * (n + 1) / (4 * k);
		for(int i = 1; i <= n; i++){
			cout << (i + a) << " ";
		}
		cout << "\n";
	}
	
    return 0;
}
