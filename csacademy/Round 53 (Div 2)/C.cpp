#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
long d[MAX];
long *st;
long *stpos;

long getMid(long s, long e) {  return s + (e -s)/2;  }

long RMQUtil(long ss, long se, long qs, long qe, long index, long &rindex)
{
	rindex = stpos[index];
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return LONG_MAX;
    long mid = getMid(ss, se);
    long rindex1, rindex2;
    long rm1 = RMQUtil(ss, mid, qs, qe, 2*index+1, rindex1);
    long rm2 = RMQUtil(mid+1, se, qs, qe, 2*index+2, rindex2);
    if(rm1 < rm2){
    	rindex = rindex1;
    	return rm1;
	}
	else{
    	rindex = rindex2;
		return rm2;
	}
}

long constructSTUtil(long arr[], long ss, long se, long si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        stpos[si] = ss;
        return arr[ss];
    }
    long mid = getMid(ss, se);
    long rm1 = constructSTUtil(arr, ss, mid, si*2+1);
    long rm2 = constructSTUtil(arr, mid+1, se, si*2+2);
    if(rm1 < rm2){
    	st[si] = rm1;
    	stpos[si] = stpos[si*2+1];
	}
	else{
    	st[si] = rm2;
    	stpos[si] = stpos[si*2+2];		
	}
    return st[si];
}

void constructST(long arr[], long n)
{
    long x = (int)(ceil(log2(n))); 
    long max_size = 2*(long)pow(2, x) - 1; 
    st = new long[max_size]; 
    stpos = new long[max_size]; 
    constructSTUtil(arr, 0, n-1, 0);
}

void solve(long n, long qs, long qe, long &r){
    if(qs == qe){
    	if((qs <= 0 or d[qs - 1] != d[qs]) && (qe >= n - 1 or d[qe + 1] != d[qe]))
        	r++;
        return;
    }
    long m;
    RMQUtil(0, n-1, qs, qe, 0, m);
    if((qs <= 0 or d[qs - 1] != d[m]) && (qe >= n - 1 or d[qe + 1] != d[m]))
        r++;
    if(m > qs)
    	solve(n, qs, m - 1, r);
    if(m < qe)
    	solve(n, m + 1, qe, r);
}

int main() {
    long n;
    cin >> n;
    for(long i = 0; i < n; i++)
        scanf("%ld", &d[i]);
    constructST(d, n);
    long r = 0;
    solve(n, 0, n - 1, r);
    cout << r;
    return 0;
}
