package projects;

import algorithms.NumberTheoryUtils;
import utils.FastReader;
import utils.Triplet;

public class ProjectEuler005 {

    public static void main(String[] args){
        FastReader f = new FastReader();
        int n, t = f.nextInt();
        long r;
        Triplet<Long, Long, Long> gcd;
        while(t-- > 0){
            n = f.nextInt();
            r = 1;
            for(int i = 2; i <= n; i++){
                gcd = NumberTheoryUtils.gcdExtended(r, i);
                r = r * i / gcd.first;
            }
            System.out.println(r);
        }
    }
}
