package projects;

import algorithms.EratosthenesSieve;
import utils.FastReader;

public class ProjectEuler007 {
    private static final int MAX_SIZE = 1000001;

    public static void main(String[] args){
        EratosthenesSieve e = new EratosthenesSieve(MAX_SIZE);
        FastReader f = new FastReader();
        int n, t = f.nextInt();
        while(t-- > 0){
            n = f.nextInt();
            System.out.println(e.getPrime(n - 1));
        }
    }
}
