#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, k, h, c, d;
	scanf("%lld %lld", &n, &k);
	h = n / 2;
	d = h / (k + 1);
	c = d * k;
	cout << d << " " << c << " " << (n - c - d);
	return 0;
}
