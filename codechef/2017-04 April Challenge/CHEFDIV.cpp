#include <bits/stdc++.h>
#define fi "CHEFDIV.in"
#define fo "CHEFDIV.out"
#define MAX 50

using namespace std;

long long modular_pow(long long base, int exponent, long long modulus){
    long long result = 1;
    while (exponent > 0){
        if (exponent & 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

long long PollardRho(long long n){
    srand (time(NULL));
    if (n == 1) return n;
    if (!n & 1) return 2;
    long long x = (rand() % (n - 2)) + 2;
    long long y = x;
    long long c = (rand() % (n - 1)) + 1;
    long long d = 1; 
    while (d == 1){
        x = (modular_pow(x, 2, n) + c + n) % n;
        y = (modular_pow(y, 2, n) + c + n) % n;
        y = (modular_pow(y, 2, n) + c + n) % n;
        d = __gcd(abs(x - y), n);
        if (d == n) return PollardRho(n);
    }
    return d;
}

vector<int> generatePrimeFactors(long long n){
    long long fact = PollardRho(n);
    int pow = 1;
    vector<int> pows;
    while (n > 1){
        n /= fact;
        if (!n % fact){
            pow++;
            continue;
        }
		pows.push_back(pow);
        fact = PollardRho(n);
        pow = 1;
    }
    return pows;
}

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
    // code here
    long long a, b, r = 0, mult;
    int cur;
    vector<int> pows;
    int pcount[MAX];
    scanf("%lld %lld", &a, &b);
    for(long long i = a; i <= b; i++){
    	pows.clear();
    	pows = generatePrimeFactors(i);
    	memset(pcount, 0, sizeof pcount);
    	mult = 1;
    	for(vector<int>::iterator it = pows.begin(); it != pows.end(); it++){
    		mult *= *it + 1;
    		pcount[*it - 1]++;
		}
		r += mult;
		cur = MAX - 1;
		while(cur >= 0){
			if(!pcount[cur]){
				cur--;
				continue;
			}
			mult = (mult / (cur + 2)) * (cur + 1);
			pcount[cur]--;
			if(cur > 0)
				pcount[cur - 1]++;
			r += mult;
		}
		r--;
	}
	printf("%lld", r);
    
	return 0;
}
