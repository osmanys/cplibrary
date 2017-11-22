#include <bits/stdc++.h>
#define LEVEL 18
#define MOD 1000000007
 
using namespace std;
long root[LEVEL];
long long table[LEVEL][1L << LEVEL];
long long coeff[LEVEL];

long power(long x, long y, long m){
    if (y == 0)
        return 1;
    long p = power(x, y / 2, m) % m;
    p = (1LL * p * p) % m; 
    return (y % 2 == 0) ? p : (1LL * x * p) % m;
}

long modInverse(long n, long m){
    return power(n, m - 2, m);
}

int calc(int n){
	memset(table, 0, sizeof table);
	table[0][0] = 1;
	for(int i = 0; i < n; i++)
		table[1][1L << i] = 1;	
	int c = n + 2;
	for(int l = 2; l <= c; l++){
		for(int v = 0; v < n; v++){
			for(long i = 0; i < (1L << (l - 1)); i++){
				if((i >> v) & 1)
					table[l][i - (1L << v)] = (table[l][i - (1L << v)] + table[l - 1][i] * root[v]) % MOD;
				else
					table[l][i + (1L << v)] = (table[l][i + (1L << v)] + table[l - 1][i]) % MOD;
			}
		}
	}
	/*for(int l = 0; l < n; l++)
		for(long i = 0; i < (1L << 16); i++){
			if(table[l][i] < 0)
				printf("%d %ld\n", l, i);
		}*/
	memset(coeff, 0, sizeof coeff);
	coeff[c] = 1;
	c -= 2;
	while(c > 0){
		
	}
	return c;
}

int main() {
	int t, n, c;
	long r;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%ld", &root[i]);
		c = calc(n);
		printf("%d\n", c);
		for(int i = 0; i <= c; i++)
			printf("%d ", coeff[i] % MOD);
		printf("\n");
	}	
    return 0;
}
