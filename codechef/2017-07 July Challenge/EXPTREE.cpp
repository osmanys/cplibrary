#include <bits/stdc++.h>
#define M7 1000000007
#define M9 1000000009
#define F7 125000001
#define F9 875000008
 
using namespace std;

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

int main(){
	long t, r7, r9, n7, n9;
	long long n;
	scanf("%ld", &t);
	while(t--){
		scanf("%lld", &n);
		n7 = n % M7;
		r7 = (1LL * F7 * (2LL * n7 + 1) + 3LL * modInverse((16LL * n7 - 24) % M7, M7)) % M7;
		n9 = n % M9;
		r9 = (1LL * F9 * (2LL * n9 + 1) + 3LL * modInverse((16LL * n9 - 24) % M9, M9)) % M9;
		printf("%ld %ld\n", r7, r9);
	}
    return 0;
}
