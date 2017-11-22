#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long pow(long long a, long long b, long long mod){
    long long x = 1, y = a; 
    while(b > 0){
        if(b % 2)
            x = (x * y) % mod;
        y = (y * y) % mod;
        b /= 2;
    }
    return x % mod;
}

long long InverseEuler(long long n, long long mod){
    return pow(n, mod - 2, mod);
}
 
long long C(long long n, long long r, long long mod){
    vector<long long> f(n + 1, 1);
    for (long long i = 2; i <= n; i++)
        f[i] = (f[i-1] * i) % mod;
    return (f[n] * ((InverseEuler(f[r], mod) * InverseEuler(f[n-r], mod)) % mod)) % mod;
}

int main(){
	//printf("%lld\n", C(100000, 50000, MOD));
	long n, k;
	long long v, d, max = 0;
	scanf("%ld %ld", &n, &k);
	vector<long long> values, filtered;	
	for(long i = 0; i < n; i++){
		scanf("%lld", &d);
		values.push_back(d);
		if(max < d)
			max = d;
	}
	int bit = 0;
	while(max >> bit){
		bit++;
	}
	for(int i = bit; i > 0; i--){
		filtered.clear();
		for(vector<long long>::iterator it = values.begin(); it != values.end(); it++){
			if((*it >> (i - 1)) & 1)
				filtered.push_back(*it);
		}
		if(filtered.size() >= k)
			values = filtered;
	}
	v = (1L << (bit + 2)) - 1;
	for(long i = 0; i < k; i++){
		v &= values[i];
	}
	printf("%lld\n", v);
	printf("%lld\n", C(values.size(), k, MOD));
	
	return 0;
}
