package projects;

import utils.FastReader;

public class ProjectEuler008 {

    public static void main(String[] args){
        FastReader f = new FastReader();
        int n, k, t = f.nextInt();
        String d;
        int mr, r;
        while(t-- > 0){
            n = f.nextInt();
            k = f.nextInt();
            d = f.nextLine();
            r = 1;
            for(int i = 0; i < k; i++)
                r *= Character.getNumericValue(d.charAt(i));
            mr = r;
            for(int i = k; i < n; i++){
                if(d.charAt(i - k) != '0')
                    r = r * Character.getNumericValue(d.charAt(i)) / Character.getNumericValue(d.charAt(i - k));
                else{
                    r = 1;
                    for(int j = i - k + 1; j < i + 1; j++)
                        r *= Character.getNumericValue(d.charAt(j));
                }
                if(r > mr)
                    mr = r;
            }
            System.out.println(mr);
        }
    }
}
