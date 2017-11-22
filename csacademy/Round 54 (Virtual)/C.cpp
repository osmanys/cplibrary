#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
long d[MAX];
long *st;
long *stpos;

long getMid(long s, long e) {  return s + (e - s) / 2;  }

long RMQ(long qs, long qe, long ss, long se, long index, long &rindex){
	rindex = stpos[index];
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return LONG_MAX;
    long mid = getMid(ss, se);
    long rindex1, rindex2;
    long rm1 = RMQ(qs, qe, ss, mid, 2 * index + 1, rindex1);
    long rm2 = RMQ(qs, qe, mid + 1, se, 2 * index + 2, rindex2);
    if(rm1 < rm2){
    	rindex = rindex1;
    	return rm1;
	}
	else{
    	rindex = rindex2;
		return rm2;
	}
}

long constructSTUtil(long arr[], long ss, long se, long si){
    if (ss == se){
        st[si] = arr[ss];
        stpos[si] = ss;
        return arr[ss];
    }
    long mid = getMid(ss, se);
    long rm1 = constructSTUtil(arr, ss, mid, si * 2 + 1);
    long rm2 = constructSTUtil(arr, mid+1, se, si * 2 + 2);
    if(rm1 < rm2){
    	st[si] = rm1;
    	stpos[si] = stpos[si * 2 + 1];
	}
	else{
    	st[si] = rm2;
    	stpos[si] = stpos[si * 2 + 2];
	}
    return st[si];
}

void constructST(long arr[], long n){
    long x = (int)(ceil(log2(n))); 
    long max_size = 2 * (long)pow(2, x) - 1; 
    st = new long[max_size]; 
    stpos = new long[max_size]; 
    constructSTUtil(arr, 0, n - 1, 0);
}

int main() {
    long n, k;
    cin >> n >> k;
    for(long i = 0; i < n; i++)
        scanf("%ld", &d[i]);
    constructST(d, n);
    long r, m;
    for(long i = 0; i < n; i++){
        m = RMQ(i, min(i + k, n - 1), 0, n - 1, 0, r);
        if(d[i] > m){
            swap(d[i], d[r]);
            break;
        }
    }
    for(long i = 0; i < n; i++)
        printf("%ld ", d[i]);
    return 0;
}
