#include <bits/stdc++.h>
#define MAX 500001

using namespace std;
long sieve[MAX];
bool prime[MAX];

void sieveOfEratosthenes(long n){
	long long i, j;
    for (i = 2; i <= n; i += 2)
        sieve[i] = 2;
    for (i = 3; i <= n; i += 2){
        if (!prime[i]){
            sieve[i] = i;
            for (j = i; i * j <= n; j += 2){
                if (!prime[i * j]){
                    prime[i * j] = true;
                    sieve[i * j] = i;
                }
            }
        }
    }
}

long generateFactors(long n){ 
    long curr = sieve[n], cnt = 1, f = 1;
    while (n > 1){
        n /= sieve[n];
        if (curr == sieve[n]){
            cnt++;
            continue;
        }
        if(cnt & 1)
        	f *= curr;
        curr = sieve[n];
        cnt = 1;
    }
    return f;
}

long geometricTrick(long n, string s){
	sieveOfEratosthenes(n);
	long result = 0, _sqrt, f, i, j;
	for(i = 1; i <= n; i++){
		f = generateFactors(i);
		_sqrt = sqrt(i / f);
		for(j = _sqrt + 1; j * j * f <= n; j++){
			if((s[i - 1] == 'a' && s[j * f * _sqrt - 1] == 'b' && s[j * j * f - 1] == 'c') || (s[i - 1] == 'c' && s[j * f * _sqrt - 1] == 'b' && s[j * j * f - 1] == 'a'))
				result++;
		}
	}
	return result;
}

int main() {
    long n;
    cin >> n;
    string s;
    cin >> s;
    printf("%ld", geometricTrick(n, s));
    return 0;
}
