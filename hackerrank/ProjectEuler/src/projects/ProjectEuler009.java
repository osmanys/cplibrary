package projects;

import utils.FastReader;

public class ProjectEuler009 {

    public static void main(String[] args){
        FastReader f = new FastReader();
        int mr, b, n, t = f.nextInt();
        while(t-- > 0){
            n = f.nextInt();
            mr = -1;
            for(int a = 1; a < n / 2; a++){
                if((n * n - 2 * n * a) % (2 * n - 2 * a) == 0){
                    b = (n * n - 2 * n * a) / (2 * n - 2 * a);
                    if(mr < a * b * (n - a - b))
                        mr = a * b * (n - a - b);
                }
            }
            System.out.println(mr);
        }
    }
}
