long long *BITree;

long long getSum(BITree, long index){
    long long sum = 0;
    index++;
    while (index){
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(BITree, long n, long index, long long val){
    index++;
    while (index <= n){
       BITree[index] += val;
       index += index & (-index);
    }
}

void constructBITree(BITree, long long arr[], long n){
    BITree = new long long[n + 1];
    for (long i = 1; i <= n; i++)
        BITree[i] = 0;
    for (long i = 0; i < n; i++)
        updateBIT(n, i, arr[i]);
}

long long* constructBITree(long n){
    long long *BITree = new long long[n + 1];
    for (long i = 1; i <= n; i++)
        BITree[i] = 0;
    return BITree;
}