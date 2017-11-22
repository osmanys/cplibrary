package projects;

import utils.FastReader;

public class ProjectEuler013 {

    public static void main(String[] args){
        FastReader f = new FastReader();
        int n = f.nextInt();
        String s;
        int[][] d = new int[n][50];
        int[] r = new int[55];
        for(int i = 0; i < n; i++){
            s = f.nextLine();
            for(int j = 0; j < 50; j++)
                d[i][j] = s.charAt(j) - '0';
        }
        int sum, rem = 0;
        for(int j = 49; j >= 0; j--){
            sum = rem;
            for(int i = 0; i < n; i++)
                sum += d[i][j];
            r[j + 5] = sum % 10;
            rem = sum / 10;
        }
        r[4] = rem % 10;
        r[3] = (rem / 10) % 10;
        r[2] = (rem / 100) % 10;
        r[1] = (rem / 1000) % 10;
        r[0] = (rem / 10000) % 10;
        int c = 0;
        while (c < 55 && r[c] == 0)
            c++;
        for(int i = 0; i < 10; i++)
            System.out.print(r[i + c]);
    }
}
