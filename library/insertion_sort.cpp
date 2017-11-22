void insertionsort(int arr[],int n){
    int i,j,t;
    for(i=1;i<n;i++){
		t = arr[i];
		for(j=i-1;(j>=0)&&(arr[j]>t);j--)
			arr[j+1]=arr[j];
        arr[j+1]=t;
    }
}

Performance O(n2)