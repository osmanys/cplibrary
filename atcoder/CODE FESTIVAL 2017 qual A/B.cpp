#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if((m - j) * i + (n - i) * j == k){
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
