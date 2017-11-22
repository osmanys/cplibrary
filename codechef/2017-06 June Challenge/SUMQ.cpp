#include <bits/stdc++.h>
#define MAX 100001
#define MOD 1000000007
 
using namespace std;
long a[MAX];
long ca[MAX];
long sa[MAX];
long b[MAX];
long c[MAX];
long cc[MAX];
long sc[MAX];
 
int main(){
	int t;
	long i, p, q, r, cb, result;
	scanf("%d", &t);
	while(t--){
		scanf("%ld %ld %ld", &p, &q, &r);
		for(i = 0; i < p; i++)
			scanf("%ld", &a[i]);
		for(i = 0; i < q; i++)
			scanf("%ld", &b[i]);
		for(i = 0; i < r; i++)
			scanf("%ld", &c[i]);
		sort(b, b + q);
		sort(a, a + p);
		sa[0] = 0;
		cb = 0;
		for(i = 0; i < p; i++){
			sa[i + 1] = (sa[i] + a[i]) % MOD;			
			while(cb < q && a[i] > b[cb]){
				ca[cb] = i;
				cb++;				
			}
		}
		for(i = cb; i < q; i++)
			ca[i] = p;
		sort(c, c + r);
		sc[0] = 0;
		cb = 0;
		for(i = 0; i < r; i++){
			sc[i + 1] = (sc[i] + c[i]) % MOD;
			while(cb < q && c[i] > b[cb]){
				cc[cb] = i;
				cb++;				
			}
		}
		for(i = cb; i < q; i++)
			cc[i] = r;
		result = 0;
		for(i = 0; i < q; i++)
			result = (result + ((1LL * ca[i] * cc[i]) % MOD) * ((1LL * b[i] * b[i]) % MOD) + b[i] * ((1LL * cc[i] * sa[ca[i]] + 1LL * ca[i] * sc[cc[i]]) % MOD) + 1LL * sa[ca[i]] * sc[cc[i]]) % MOD;
		cout << result << endl;
	}
	return 0;
}
