
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