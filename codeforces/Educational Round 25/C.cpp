#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long k, t;
	scanf("%d %ld", &n, &k);
	long d[n];
	for(int i = 0; i < n; i++){
		scanf("%ld", &t);
		d[i] = t;		
	}
	sort(d, d + n);
	long m = 0;
	int i = 0;
	for(; i < n; i++)
		if(d[i] > k)
			break;
	m = k;
	int r = 0;
	for(; i < n; i++){
		while(d[i] > 2 * m){
			m = 2 * max(k, m);
			r++;
		}
		m = max(m, d[i]);
	}
	printf("%d", r);
	return 0;
}
