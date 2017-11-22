#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
long long d[MAX];
long long _asc[MAX], _desc[MAX];

int main(){
	long n;
	long long m, b;
	scanf("%ld", &n);
	for(long i = 0; i < n; i++)
		scanf("%ld", &d[i]);
	m = 0;
	for(long i = 0; i < n; i++){
		m = max(d[i], m + 1);
		_asc[i] = m;
	}
	m = 0;
	for(long i = n - 1; i >= 0; i--){
		m = max(d[i], m + 1);
		_desc[i] = m;
	}
	b = min(_asc[0], _desc[0]);
	long long r = b - d[0];
	for(long i = 1; i < n; i++){
		m = min(_asc[i], _desc[i]);
		r += m - d[i];
		if(m == b)
			r++;
		b = m;
	}
	cout << r;
	return 0;
}
