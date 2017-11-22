vector<long long> f;
vector<int> p;

void sieveOfEratosthenes(long long n, long long s[]){
    vector<bool> prime(n + 1, false);
    for (long long i = 2; i <= n; i += 2)
        s[i] = 2;
    for (long long i = 3; i <= n; i += 2){
        if (prime[i] == false){
            s[i] = i;
            for (long long j = i; j * i <= n; j += 2){
                if (prime[i * j] == false){
                    prime[i * j] = true;
                    s[i * j] = i;
                }
            }
        }
    }
}
// using sieve O(logn) and O(n) space
void primeFactors(long long n){
	f.clear();
	p.clear();
    long long s[n + 1];
    sieveOfEratosthenes(n, s);
    long long fact = s[n];
    int pow = 1;
    while (n > 1){
        n /= s[n];
        if (fact == s[n]){
            pow++;
            continue;
        }
		f.push_back(fact);
		p.push_back(pow);
        fact = s[n];
        pow = 1;
    }
}

// O(sqrt(n)) without sieve
void primeFactors(long n){
	f.clear();
	long fact = 1;
    while (n % 2 == 0){
    	fact *= 2;
        n = n / 2;
    }
    if(fact != 1)
    	f.push_back(fact);
    for (long i = 3; i <= sqrt(n); i += 2){
    	fact = 1;
        while (n % i == 0){
    		fact *= i;
            n = n / i;
        }
	    if(fact != 1)
	    	f.push_back(fact);
    }
    if (n > 2)
	    f.push_back(n);
}
