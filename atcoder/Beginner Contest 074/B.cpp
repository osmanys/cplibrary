#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int x[n];
	for(int i = 0; i < n; i++)
		cin >> x[i];
	int r = 0;
	for(int i = 0; i < n; i++)
		r += 2 * min(x[i], abs(x[i] - k));
	cout << r;
	
	return 0;
}
