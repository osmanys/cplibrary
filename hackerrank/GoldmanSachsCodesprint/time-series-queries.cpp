#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
long t[MAX];
long p[MAX];
long q1[MAX], q2[MAX];

int main(){
	int n, q, tp;
	long v, r, k;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%ld", &t[i]);
	for(int i = 0; i < n; i++)
		scanf("%ld", &p[i]);
	q1[0] = p[0];
	for(int i = 1; i < n; i++)
		q1[i] = max(q1[i - 1], p[i]);
	q2[n - 1] = p[n - 1];
	for(int i = n - 2; i >= 0; i--)
		q2[i] = max(q2[i + 1], p[i]);
	for(int i = 0; i < q; i++){
		scanf("%d %ld", &tp, &v);
		if(tp == 1){
			k = lower_bound(q1, q1 + n, v) - q1;
			r = (k == n) ? -1 : t[k];
		}
		else{
			k = lower_bound(t, t + n, v) - t;
			r = (k == n) ? -1 : q2[k];			
		}
		printf("%ld\n", r);
	}
	return 0;
}
