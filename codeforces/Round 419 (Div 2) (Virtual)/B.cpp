#include <bits/stdc++.h>
#define MAX 2000001

using namespace std;
long begins[MAX];
long _end[MAX];
long _count[MAX];

int main(){
	long n, k, q, l, r, a, b;
	scanf("%ld %ld %ld", &n, &k, &q);
	for(long i = 0; i < n; i++){
		scanf("%ld %ld", &l, &r);
		begins[l]++;
		_end[r]++;
	}
	for(long i = 1; i < MAX; i++){
		begins[i] += begins[i - 1];
		_end[i] += _end[i - 1];
		_count[i] = _count[i - 1] + (begins[i] - _end[i - 1] >= k);
	}
	for(long i = 0; i < q; i++){
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", _count[b] - _count[a - 1]);
	}
	return 0;
}
