#include <bits/stdc++.h>
#define MAX 1000000
#define MAXQ 1000000
#define MAXSZ 100000000
 
using namespace std;
long a[MAX], b[MAXQ];
long zind[MAX], zst[MAX];
long *st = new long[MAXSZ];

long getQuad(long s, long e) {  return (e - s) / 4;  }

long mult(long *st, long qs, long qe, long ss, long se, long index, long mod){
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 1;
    long qid = getQuad(ss, se);
    long rm1 = mult(st, qs, qe, ss, ss + qid, index * 4 + 1, mod);
    long rm2 = mult(st, qs, qe, ss + qid + 1, qid ? ss + 2 * qid : se, index * 4 + 2, mod);
    long rm3 = qid ? mult(st, qs, qe, ss + 2 * qid + 1, ss + 3 * qid, index * 4 + 3, mod) : 1;
    long rm4 = qid ? mult(st, qs, qe, ss + 3 * qid + 1, se, index * 4 + 4, mod) : 1;
    return (((1LL * rm1 * rm2) % mod) * ((1LL * rm3 * rm4) % mod)) % mod;
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
    long qid = getQuad(ss, se);
    long rm1 = constructSTUtil(st, arr, ss, ss + qid, si * 4 + 1, mod);
    long rm2 = constructSTUtil(st, arr, ss + qid + 1, qid ? ss + 2 * qid : se, si * 4 + 2, mod);
    long rm3 = qid ? constructSTUtil(st, arr, ss + 2 * qid + 1, ss + 3 * qid, si * 4 + 3, mod) : 1;
    long rm4 = qid ? constructSTUtil(st, arr, ss + 3 * qid + 1, se, si * 4 + 4, mod) : 1;
    st[si] = (((1LL * rm1 * rm2) % mod) * ((1LL * rm3 * rm4) % mod)) % mod;
    if(!st[si] && rm1 && rm2 && rm3 && rm4){
    	zind[se] = se;
        zst[se] = ss;
    }
    return st[si];
}

void constructST(long arr[], long n, long mod){
    memset(zind, -1, sizeof zind);
    memset(zst, -1, sizeof zst);
    constructSTUtil(st, arr, 0, n - 1, 0, mod);
    for(long i = 1; i < n; i++)
    	if(zind[i] == -1)
    		zind[i] = zind[i - 1];
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
			a[i] = rand() % 1000000000 + 1;
		constructST(a, n, p);
		for(long i = 0; i < floor(q / 64) + 2; i++)
			//scanf("%ld", &b[i]);
			b[i] = rand() % n;
		x = 0;
		c = 0;c1 = 0;
		tm = time(NULL);
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
				if(!result){
					c++;
					//zst[zind[r]] = max(zst[zind[r]], l);
				}
				c1++;
			}
			else{
				result = 0;
				shift = min((i / 64 + 1) * 64 - i - 1, zst[zind[r]] - l);
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
