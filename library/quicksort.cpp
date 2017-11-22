(Lomuto Partition scheme)
int partition(int arr[],int start,int end){ 
    int pivot=arr[end];
    int i=(start-1);
    for(int j=start;j<end;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return (i+1);
}
(Hoare Partition)
int partition(int arr[],int start,int end){ 
    int pivot=arr[start];
    int left=start;
    int right=end;
	int temp;
    while(left<right){
        while(arr[right]>pivot)
            right--;
        while((left<right)&&(arr[left]<=pivot))
            left++;
        if(left<right){
            temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
        }
    }
    temp=arr[right];
    arr[right]=arr[start];
    arr[start]=temp;
    return right;
}
(peor opcion, mantiene el orden de los elementos)
int partition(int arr[],int start,int end){ 
    int pivot=arr[start];
	vector<int> left,equal,right;
	for(int i=start;i<=end;i++){
		if(arr[i]<pivot)
			left.push_back(arr[i]);
		else if(arr[i]>pivot)
			right.push_back(arr[i]);
		else
			equal.push_back(arr[i]);
	}
	int k=start;
	for(int i=0;i<=left.size();i++,k++){
		arr[k]=left[i];
	}
	int newpivot=k;
	for(int i=0;i<=equal.size();i++,k++){
		arr[k]=equal[i];
	}
	for(int i=0;i<=right.size();i++,k++){
		arr[k]=right[i];
	}
    return newpivot;
}
void quicksort(int arr[],int start,int end){
    if(start<end){
        int pivot=partition(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}

Performance O(n*logn)