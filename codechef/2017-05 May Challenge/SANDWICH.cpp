#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<long, int> > primeFactors(long n){
    vector<pair<long, int> > result;
    int cnt = 0;
    while (n % 2 == 0){
    	cnt++;
        n = n / 2;
    }
    if(cnt)
    	result.push_back(make_pair(2, cnt));
    for (long i = 3; i <= sqrt(n); i += 2){
    	cnt = 0;
        while (n % i == 0){
        	cnt++;
            n /= i;
        }
	    if(cnt)
	    	result.push_back(make_pair(i, cnt));
    }
    if (n > 2)
	    result.push_back(make_pair(n, 1));
	return result;
}

typedef vector<long> VI;
typedef pair<long, int> PII;

// return a % b (positive value)
long mod(long a, long b) {
    return ((a % b) + b) % b;
}

// computes gcd(a,b)
long gcd(long a, long b) {
    long tmp;
    while(b){a %= b; tmp = a; a = b; b = tmp;}
    return a;
}

// computes lcm(a,b)
/*int lcm(int a, int b) {
    return a/gcd(a,b)*b;
}*/

// returns d = gcd(a,b); finds x,y such that d = ax + by
long extended_euclid(long a, long b, long &x, long &y) {  
    long xx = y = 0;
    long yy = x = 1;
    while (b) {
		long q = a / b;
		long t = b; b = a % b; a = t;
		t = xx; xx = x - q * xx; x = t;
		t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

// finds all solutions to ax = b (mod n)
/*VI modular_linear_equation_solver(int a, int b, int n) {
    int x, y;
    VI solutions;
    int d = extended_euclid(a, n, x, y);
    if (!(b%d)) {
	x = mod (x*(b/d), n);
	for (int i = 0; i < d; i++)
	    solutions.push_back(mod(x + i*(n/d), n));
    }
    return solutions;
}*/

// computes b such that ab = 1 (mod n), returns -1 on failure
long mod_inverse(long a, long n) {
    long x, y;
    long d = extended_euclid(a, n, x, y);
    if (d > 1) return -1;
    return mod(x, n);
}

// Chinese remainder theorem (special case): find z such that
// z % x = a, z % y = b.  Here, z is unique modulo M = lcm(x,y).
// Return (z,M).  On failure, M = -1.
PII chinese_remainder_theorem(long x, long a, long y, long b) {
    long s, t;
    long d = extended_euclid(x, y, s, t);
    if (a % d != b % d) return make_pair(0, -1);
    return make_pair(mod(s * b * x + t * a * y, x * y) / d, x * y / d);
}

// Chinese remainder theorem: find z such that
// z % x[i] = a[i] for all i.  Note that the solution is
// unique modulo M = lcm_i (x[i]).  Return (z,M).  On 
// failure, M = -1.  Note that we do not require the a[i]'s
// to be relatively prime.
PII chinese_remainder_theorem(const VI &x, const VI &a) {
    PII ret = make_pair(a[0], x[0]);
    for (long i = 1; i < x.size(); i++) {
		ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
		if (ret.second == -1) break;
    }
    return ret;
}

// computes x and y such that ax + by = c; on failure, x = y =-1
/*void linear_diophantine(int a, int b, int c, int &x, int &y) {
    int d = gcd(a,b);
    if (c%d) {
	x = y = -1;
    } else {
	x = c/d * mod_inverse(a/d, b/d);
	y = (c-a*x)/b;
    }
}*/

// compute a^b % m
long power_mod(long a, long b, long m) {
    if (b == 0) {
		return 1;
    } else if (b == 1) {
		return a % m;
    } else {
		long long tmp = power_mod(a, b >> 1, m);
		if (b % 2 == 0) {
		    return tmp * tmp % m;
		} else {
		    return tmp * tmp * a % m;
		}
    }
}

// compute n! = a * p^e, return (a, e), p is a prime
PII fact_mod(long long n, long p, const VI& facts) {
    if (n == 0) return make_pair(1, 0);
    PII tmp = fact_mod(n / p, p, facts);
    long long a = tmp.first;
    long e = tmp.second;
    e += n / p;
    if (n / p % 2 != 0) return make_pair(a * (p - facts[n % p]) %p, e);
    else return make_pair(a * facts[n % p] % p, e);
}



// compute n!! (mod m), m is of type p^a, where p is a prime
long n_fact_fact(long long n, long m, long p, const VI& facts) {
    if (n == 0 || n == 1) {
		return 1;
    } else if (n < m) {
		return facts[n] * n_fact_fact(n / p, m, p, facts) % m;
    } else {
		long a = facts[m - 1];
		long long b = facts[n % m];
		long c = n_fact_fact(n / p, m, p, facts);
		return power_mod(a, n / m, m) * b * c % m;
    }
}

long long power(long a, long i) {
    if (i == 0) {
		return 1;
    } else if (i == 1) {
		return a;
    } else {
		long long tmp = power(a, i >> 1);
		if (i % 2 == 0) return tmp * tmp;
		else return tmp * tmp * a;
    }
}

long long comb_mod2(long long n, long long r, long m, PII pa, const VI facts, const VI& tmp) {
    long p, a;
    p = pa.first; a = pa.second;
    long b = a;
    
    while (b > 0) {
		PII t1 = fact_mod(n, p, tmp);
		PII t2 = fact_mod(r, p, tmp);
		PII t3 = fact_mod(n - r, p, tmp);
		long e1, e2, e3;
		e1 = t1.second; e2 = t2.second; e3 = t3.second;
		if (e1 >= e2 + e3 + a) return 0;
		if (e1 >= e2 + e3 + b) break;
		b = b - 1;
    }
    long long m1 = n_fact_fact(n, m, p, facts);
    long long m2 = n_fact_fact(r, m, p ,facts);
    long long m3 = n_fact_fact(n - r, m, p, facts);
    return power(p, b) * m1 * mod_inverse(m2, m) * mod_inverse(m3, m) % m;
}

VI gen_fact(long m) {
    VI ret(m, 1);
    ret.push_back(1);
    for (long i = 1; i < m; ++i) {
		if (gcd(i, m) == 1)
			ret[i] = ret[i - 1] * i % m;
		else
			ret[i] = ret[i - 1];
    }
    return ret;
}
 
int main() {
	int t, size;
	long long n, k, d, r, answer;
	long m;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld %ld", &n, &k, &m);
		d = n / k + (n % k != 0);
		r = d * k - n;
		vector<pair<long, int> > modules = primeFactors(m);
		size = modules.size();
		VI num(size);
		VI rem(size);
		for(int i = 0; i < size; i++){    		
			num[i] = pow(modules[i].first, modules[i].second);
			rem[i] = comb_mod2(r + d - 1, (r > d - 1) ? d - 1 : r, num[i], modules[i], gen_fact(num[i]), gen_fact(modules[i].first));
		}
		answer = chinese_remainder_theorem(num, rem).first;
		printf("%lld %lld\n", d, answer);
	}
	
    return 0;
}
