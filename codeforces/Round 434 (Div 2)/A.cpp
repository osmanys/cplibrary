#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
	long long n, d = 1, g;
	int k;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
		d *= 10;
	g = gcd(n, d);
	cout << (n * d / g);
	return 0;
}
