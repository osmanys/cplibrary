package projects;

import algorithms.EratosthenesSieve;
import utils.FastReader;

public class ProjectEuler010 {
    private static final int MAX_SIZE = 1000001;

    public static void main(String[] args){
        EratosthenesSieve e = new EratosthenesSieve(MAX_SIZE);
        int p = 0;
        int[] np = new int[MAX_SIZE];
        for(int i = 0; i < MAX_SIZE; i++){
            if(e.isPrime(i))
                p++;
            np[i] = p;
        }
        long[] s = new long[e.size() + 1];
        s[0] = 0;
        for(int i = 0; i < e.size(); i++)
            s[i + 1] = s[i] + e.getPrime(i);
        FastReader f = new FastReader();
        int n, t = f.nextInt();
        while(t-- > 0){
            n = f.nextInt();
            System.out.println(s[np[n]]);
        }
    }
}
