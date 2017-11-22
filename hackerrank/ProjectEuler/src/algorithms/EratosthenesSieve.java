package algorithms;

import utils.Pair;

import java.util.Vector;

public class EratosthenesSieve {
    private int MAX_SIZE;
    private boolean[] isprime;
    private Vector<Integer> primes;
    private int[] spf;

    public EratosthenesSieve(int MAX_SIZE){
        this.MAX_SIZE = MAX_SIZE;
        isprime = new boolean[MAX_SIZE];
        primes = new Vector<>();
        spf = new int[MAX_SIZE];
        build_sieve();
    }

    private void build_sieve(){
        for (int i = 0; i < MAX_SIZE; i++)
            isprime[i] = true;
        isprime[0] = false;
        spf[0] = 0;
        isprime[1] = false;
        spf[1] = 1;
        for (int i = 2; i < MAX_SIZE ; i++){
            if (isprime[i]){
                primes.add(i);
                spf[i] = i;
            }
            for (int j = 0; j < primes.size() && i * primes.get(j) < MAX_SIZE && primes.get(j) <= spf[i]; j++){
                isprime[i * primes.get(j)] = false;
                spf[i * primes.get(j)] = primes.get(j);
            }
        }
    }

    public boolean isPrime(int n){
        if(n >= MAX_SIZE)
            throw new IllegalArgumentException();
        return isprime[n];
    }

    public int size(){
        return primes.size();
    }

    public int getPrime(int i){
        if(i >= primes.size())
            throw new IndexOutOfBoundsException();
        return primes.get(i);
    }

    public Vector<Pair<Integer, Integer>> factorize(int n){
        Vector<Pair<Integer, Integer>> r = new Vector<>();
        int cur = spf[n];
        int cnt = 1;
        while (n > 1){
            n = n / spf[n];
            if(cur == spf[n]){
                cnt++;
                continue;
            }
            r.add(new Pair<>(cur, cnt));
            cur = spf[n];
            cnt = 1;
        }
        return r;
    }
}
