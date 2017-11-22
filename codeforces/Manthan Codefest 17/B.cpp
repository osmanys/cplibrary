#include <bits/stdc++.h>
#define MAX 100001

using namespace std;
long d[MAX];
long long m[MAX];

int main(){
	long n, p, q, r;
	cin >> n >> p >> q >> r;
	for(long i = 0; i < n; i++)
		scanf("%ld", &d[i]);
	m[n] = LLONG_MIN;
	for(long i = n - 1; i >= 0; i--)
		if(m[i + 1] < 1LL * r * d[i])
			m[i] = 1LL * r * d[i];
		else
			m[i] = m[i + 1];
	for(long i = n - 1; i >= 0; i--)
		if(m[i + 1] < m[i] + 1LL * q * d[i])
			m[i] = m[i] + 1LL * q * d[i];
		else
			m[i] = m[i + 1];
	for(long i = n - 1; i >= 0; i--)
		if(m[i + 1] < m[i] + 1LL * p * d[i])
			m[i] = m[i] + 1LL * p * d[i];
		else
			m[i] = m[i + 1];
	cout << m[0];
	return 0;
}
