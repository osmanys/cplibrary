#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, a, b;
	cin >> n;
	a = sqrt(n);
	if(a * a == n)
		b = a;
	else{
		b = a + 1;
		if(a * b < n)
			a++;
	}
	cout << (2 * (a + b));
	return 0;
}
