void countingsort(int arr[], int n){
    int c[MAX]={};
    for(int i=0;i<n;i++)
        c[arr[i]]++;
    int current=0;
    for(int i=0;i<MAX;i++)
        for(int j=0;j<c[i];j++)
            arr[current++]=i;
}

Performance O(n)