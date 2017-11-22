#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int r = 1;
	for(int i = 0; i < n; i++){
		if( 2 * r < r + k)
			r = 2 * r;
		else
			r = r + k;
	}
	cout << r;
	return 0;
}
