#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d;
	cin >> n;
	long c = 1;
	for(int i = 0; i < n; i++){
		cin >> d;
		if(!(d & 1))
			c *= 2;
	}
	cout << (pow(3L, n) - c);
	return 0;
}
