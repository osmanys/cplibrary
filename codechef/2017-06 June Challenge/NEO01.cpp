#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
long d[MAX];

int main(){
	int t;
	long n, i, k;
	long long r, max, p, partial;
	scanf("%d", &t);
	while(t--){
		scanf("%ld", &n);
		for(i = 0; i < n; i++)
			scanf("%ld", &d[i]);
		sort(d, d + n, greater<long>());
		p = 0;i = 0;
		for(; i < n && d[i] >= 0; i++)
			p += d[i];
		r = 0;
		for(k = 0; i + k < n; k++)
			r += d[i + k];
		max = r + i * p;partial = 0;
		for(k = 0; i + k < n; k++){
			partial += d[i + k];
			if(max < (i + k + 1) * (p + partial) + r - partial)
				max = (i + k + 1) * (p + partial) + r - partial;
		}
		printf("%lld\n", max);
	}
	return 0;
}
