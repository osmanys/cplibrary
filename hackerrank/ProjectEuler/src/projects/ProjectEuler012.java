package projects;

import algorithms.EratosthenesSieve;
import utils.FastReader;
import utils.Pair;

import java.util.Vector;

public class ProjectEuler012 {
    private static final int MAX_SIZE = 1000001;

    public static void main(String[] args){
        EratosthenesSieve e = new EratosthenesSieve(MAX_SIZE);
        Vector<Pair<Integer, Integer>> fact1, fact2;
        int[] maxd = new int[1001];
        int cur = 2, md = 0, d;
        while(cur < MAX_SIZE && md < 1000){
            fact1 = e.factorize(cur);
            fact2 = e.factorize(cur + 1);
            d = 1;
            for (Pair<Integer, Integer> aFact1 : fact1) d *= aFact1.second + 1;
            for (Pair<Integer, Integer> aFact2 : fact2) d *= aFact2.second + 1;
            if(fact1.get(0).first == 2)
                d = d * fact1.get(0).second / (fact1.get(0).second + 1);
            else if(fact2.get(0).first == 2)
                d = d * fact2.get(0).second / (fact2.get(0).second + 1);
            if(md < d){
                md = d;
                maxd[md > 1000 ? 1000 : md - 1] = cur;
            }
            cur++;
        }
        maxd[0] = 1;
        for(int i = 999; i >= 0; i--){
            if(maxd[i] == 0)
                maxd[i] = maxd[i + 1];
        }
        FastReader f = new FastReader();
        int n, t = f.nextInt();
        while(t-- > 0){
            n = f.nextInt();
            System.out.println(maxd[n] * (maxd[n] + 1) / 2);
        }
    }
}
