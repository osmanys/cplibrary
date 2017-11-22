package projects;

import utils.FastReader;

public class ProjectEuler011 {

    public static void main(String[] args){
        int[][] d = new int[20][20];
        FastReader f = new FastReader();
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 20; j++)
                d[i][j] = f.nextInt();
        int mr = 0;
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 20; j++){
                if(i < 17 && j < 17 && mr < d[i][j] * d[i + 1][j + 1] * d[i + 2][j + 2] * d[i + 3][j + 3])
                    mr = d[i][j] * d[i + 1][j + 1] * d[i + 2][j + 2] * d[i + 3][j + 3];
                if(i < 17 && mr < d[i][j] * d[i + 1][j] * d[i + 2][j] * d[i + 3][j])
                    mr = d[i][j] * d[i + 1][j] * d[i + 2][j] * d[i + 3][j];
                if(j < 17 && mr < d[i][j] * d[i][j + 1] * d[i][j + 2] * d[i][j + 3])
                    mr = d[i][j] * d[i][j + 1] * d[i][j + 2] * d[i][j + 3];
                if(i > 2 && j < 17 && mr < d[i][j] * d[i - 1][j + 1] * d[i - 2][j + 2] * d[i - 3][j + 3])
                    mr = d[i][j] * d[i - 1][j + 1] * d[i - 2][j + 2] * d[i - 3][j + 3];
            }
        System.out.println(mr);
    }
}
