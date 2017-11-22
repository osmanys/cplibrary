package projects;

import utils.FastReader;

public class ProjectEuler006 {

    public static void main(String[] args){
        FastReader f = new FastReader();
        int n, t = f.nextInt();
        while(t-- > 0){
            n = f.nextInt();
            System.out.println((long) n * (n + 1) * (3 * n + 2) * (n - 1) / 12);
        }
    }
}
