int lcsubstr(string x, string y){
    int lcsuff[m+1][n+1];
    int result=0; 
    for (int i=0;i<=x.length();i++){
        for (int j=0;j<=y.length();j++){
            if (!i||!j)
                lcsuff[i][j]=0; 
            else if(x[i-1]==y[j-1]){
                lcsuff[i][j]=lcsuff[i-1][j-1]+1;
                result = max(result,lcsuff[i][j]);
            }
            else lcsuff[i][j]=0;
        }
    }
    return result;
}

Performance O(n*m)