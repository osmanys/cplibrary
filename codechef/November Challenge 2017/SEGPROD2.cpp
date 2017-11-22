#include <bits/stdc++.h>
#define MAX 1000000
#define MAXQ 1000000
 
using namespace std;
long a[MAX], b[MAXQ];
long zind[MAX], zst[MAX];
long *st;

long getMid(long s, long e) {  return s + (e - s) / 2;  }

long mult(long *st, long qs, long qe, long ss, long se, long index, long mod){
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 1;
    long mid = getMid(ss, se);
    long rm1 = mult(st, qs, qe, ss, mid, 2 * index + 1, mod);
    long rm2 = mult(st, qs, qe, mid + 1, se, 2 * index + 2, mod);
    return (1LL * rm1 * rm2) % mod;
}

long constructSTUtil(long *st, long arr[], long ss, long se, long si, long mod){
    if (ss == se){
        st[si] = arr[ss] % mod;
	    if(!st[si]){
	    	zind[se] = se;
	        zst[se] = ss;
	    }
        return st[si];
    }
    long mid = getMid(ss, se);
    long rm1 = constructSTUtil(st, arr, ss, mid, si * 2 + 1, mod);
    long rm2 = constructSTUtil(st, arr, mid + 1, se, si * 2 + 2, mod);
    st[si] = (1LL * rm1 * rm2) % mod;
    if(!st[si] && rm1 && rm2){
    	zind[se] = se;
        zst[se] = ss;
    }
    return st[si];
}

long* constructST(long arr[], long n, long mod){
    long x = (int)(ceil(log2(n))); 
    long max_size = 2 * (long)pow(2, x) - 1; 
    long *st = new long[max_size];
    memset(zind, -1, n * sizeof(long));
    constructSTUtil(st, arr, 0, n - 1, 0, mod);
    long zz = 0;
    for(long i = 1; i < n; i++)
    	if(zind[i] == -1){
    		zind[i] = zind[i - 1];
    		zz++;
    	}
    	else{
    		//cout << (zz - zind[i - 1] + zst[zind[i - 1]]) << " ";
    		zz = 0;
    	}
    return st;
}
 
int main() {
	int t;
	long n, p, q, l, r, x, result, shift, tresult, c, c1, tm;
	cin >> t;
	srand(time(NULL));
	while(t--){
		//scanf("%ld %ld %ld", &n, &p, &q);
		n = 1000000;
		p = 1000000007;//rand() % (1000000000 - 1) + 2;
		q = 20000000;
		for(long i = 0; i < n; i++)
			//scanf("%ld", &a[i]);
			a[i] = rand() % 1000000001;
		for(long i = 0; i < floor(q / 64) + 2; i++)
			//scanf("%ld", &b[i]);
			b[i] = rand() % n;
		tm = time(NULL);
		st = constructST(a, n, p);
		x = 0;
		c = 0;c1 = 0;
		long zz = 0;
		for(long i = 0; i < q; i++){
			if(i % 64){
				l = (l + x) % n;
				r = (r + x) % n; 
			}
			else{
				l = (b[i / 64] + x) % n;
				r = (b[i / 64 + 1] + x) % n;
			}
			if(l > r)
				swap(l, r);
			if(zind[r] == -1 || zst[zind[r]] <= l){
				result = mult(st, l, r, 0, n - 1, 0, p);
				cout << "noshift:" << ((result + 1) % p) << " ";
				zz++;
				if(!result){
					c++;
					//zst[zind[r]] = max(zst[zind[r]], l);
				}
				c1++;
			}
			else{
				result = 0;
				//if(zz)
				//cout << zz << " ";
				zz = 0;
				shift = min((i / 64 + 1) * 64 - i - 1, zst[zind[r]] - l);
				cout << shift << " ";
				l += shift;
				r += shift;
				i += shift;
			}
			/*tresult = 1;
			for(long k = l; k <= r; k++)
				tresult = (1LL * tresult * a[k]) % p;
			if(result != tresult){
				cout << "error\n";
				tresult = 1;
				for(long k = zst[zind[r]]; k <= zind[r]; k++)
					tresult = (1LL * tresult * a[k]) % p;
			}*/
			x = (result + 1) % p;
		}
		cout << x << " " << c1 << " " << c << " " << (time(NULL) - tm) << '\n';
	}
    return 0;
}
