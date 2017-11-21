std::vector<bool> isPrime(1 + max, true);
isPrime[0] = false;
isPrime[1] = false;
for (int i = 2; i * i <= max; i++) {
    if (isPrime[i]) {
        for (int j = i * i; j <= max; j += i) {
            isPrime[j] = false;
        }
    }
}