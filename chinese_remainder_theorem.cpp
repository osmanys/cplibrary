
long modInverse(long a, long m){
    long m0 = m, t, q;
    long x0 = 0, x1 = 1; 
    if (m == 1)
      return 0; 
    while (a > 1){
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
    return x1;
}

long long findMin(long num[], long rem[], int k){
    long long prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    long long result = 0;
    for (int i = 0; i < k; i++){
        long long pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    } 
    return result % prod;
}