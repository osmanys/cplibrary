#include <bits/stdc++.h>
#define MAX 1001
 
using namespace std;
int phi[MAX];
int p[MAX][MAX];

void computeTotient(int n){
    for (int i = 1; i < n; i++)
        phi[i] = i;
    for (int p = 2; p < n; p++){
        if (phi[p] == p){
            phi[p] = p - 1;
            for (int i = 2 * p; i < n; i += p)
               phi[i] = (phi[i] / p) * (p - 1);
        }
    }
}

void computePow(int n, int t, int m){
	for(int i = 0; i <= n; i++){
		p[i][0] = 1;
		for(int j = 1; j <= t; j++)
			p[i][j] = (1L * p[i][j - 1] * i) % m;
	}
}

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
int main() {
	int t, m, r;
	long n, g, c;
	computeTotient(MAX);
	scanf("%d", &t);
	while(t--){
		scanf("%ld %d", &n, &m);
		computePow(m, phi[m], m);
		g = (1L * m * phi[m]) / gcd(m, phi[m]);
		r = 0;
		c = n / g;
		if(c){
			for(long i = 0; i < g; i++)
				r = (r + p[i % m][i % phi[m]]) % m;
		}
		r = (1LL * r * c) % m;
		for(long i = 0; i <= (n % g); i++)
			r = (r + p[i % m][i % phi[m]]) % m;
		printf("%d\n", r);
	}
    return 0;
}
