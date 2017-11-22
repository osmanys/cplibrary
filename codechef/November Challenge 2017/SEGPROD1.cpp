#include <bits/stdc++.h>
#define MAX 1000000
#define MAXQ 1000000
#define MAXF 30
 
using namespace std;
long a[MAX], b[MAXQ];
vector<long> fct;
vector<long> pw;
vector<long> mlt;
long m[MAXF][MAX], inv[MAXF][MAX], ap[MAXF][MAX], zrs[MAX];

long zind[MAX], zst[MAX];
long *st = new long[10000000];

long getMid(long s, long e) {  return s + (e - s) / 2;  }

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

void constructST(long arr[], long n, long mod){
    memset(zind, -1, n * sizeof(long));
    constructSTUtil(st, arr, 0, n - 1, 0, mod);
    for(long i = 1; i < n; i++)
    	if(zind[i] == -1)
    		zind[i] = zind[i - 1];
}

void primeFactors(long n){
	fct.clear();
	pw.clear();
	mlt.clear();
	int p = 0;
    while (!(n % 2)){
    	p++;
        n = n / 2;
    }
    if(p){
    	fct.push_back(2);
    	pw.push_back(p);
    	mlt.push_back(pow(2, p));
	}
    for (long i = 3; i <= sqrt(n); i += 2){
    	p = 0;
        while (!(n % i)){
    		p++;
            n = n / i;
        }
	    if(p){
	    	fct.push_back(i);
	    	pw.push_back(p);
    		mlt.push_back(pow(i, p));
	    }
    }
    if (n > 2){
	    fct.push_back(n);
	    pw.push_back(1);
    	mlt.push_back(n);
	}
}

long modInverse(long a, long m){
    long m0 = m, t, q;
    long x0 = 0, x1 = 1; 
    if (m == 1)
      return 0; 
    while (a > 1){
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
    return x1;
}

long findMin(long l, long r){
    long pp, rem, prod = 1;
    for (int i = 0; i < fct.size(); i++)
		prod *= mlt[i];
    long long result = 0;
    for (int i = 0; i < fct.size(); i++){
        pp = prod / mlt[i];
        if(ap[i][r] - (l ? ap[i][l - 1] : 0) >= pw[i])
        	rem = 0;
		else{
			rem = (1LL * m[i][r] * (l ? inv[i][l - 1] : 1)) % mlt[i];
			rem = (1LL * rem * (long)pow(fct[i], ap[i][r] - (l ? ap[i][l - 1] : 0))) % mlt[i];
		}
        result += 1LL * rem * modInverse(pp, mlt[i]) * pp;
    } 
    return result % prod;
}
 
int main() {
	int t;
	long n, p, q, l, r, x, result, z, tm, tresult;
	long long _pow;
	cin >> t;
	srand(time(NULL));
	while(t--){
		//scanf("%ld %ld %ld", &n, &p, &q);
		n = 1000000;
		p = 1000000007;//rand() % (1000000000 - 1) + 2;//7*7*124897;//2*3*4*5*6*7*8*9*10*11*12*13*14;
		q = 2000;
		z = 0;
		for(long i = 0; i < n; i++){
			//scanf("%ld", &a[i]);
			a[i] = rand() % p;
			if(!a[i])
				z++;
			zrs[i] = z;
		}
		for(long i = 0; i < floor(q / 64) + 2; i++)
			//scanf("%ld", &b[i]);
			b[i] = rand() % n;
		tm = time(NULL);
		constructST(a, n, p);
		primeFactors(p);
		for(int i = 0; i < fct.size(); i++){
			ap[i][0] = 0;
			if(a[0]){
				_pow = fct[i];
				while(!(a[0] % _pow)){
					_pow *= fct[i];
					ap[i][0]++;
				}
				_pow /= fct[i];
				m[i][0] = (a[0] / _pow) % mlt[i];
				inv[i][0] = modInverse(m[i][0], mlt[i]);
			}
			else{
				m[i][0] = 1;
				inv[i][0] = 1;
			}
			for(long j = 1; j < n; j++){
				ap[i][j] = ap[i][j - 1];
				if(a[j]){
					_pow = fct[i];
					while(!(a[j] % _pow)){
						_pow *= fct[i];
						ap[i][j]++;
					}
					_pow /= fct[i];
					m[i][j] = (1LL * m[i][j - 1] * a[j] / _pow) % mlt[i];
					inv[i][j] = modInverse(m[i][j], mlt[i]);
				}
				else{
					m[i][j] = m[i][j - 1];
					inv[i][j] = inv[i][j - 1];
				}
			}
		}
		x = 0;
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
			if(!(zrs[r] - (l ? zrs[l - 1] : 0)) && (zind[r] == -1 || zst[zind[r]] <= l))
				result = findMin(l, r);
			else
				result = 0;
			tresult = 1;
			for(long k = l; k <= r; k++)
				tresult = (1LL * tresult * a[k]) % p;
			if(result != tresult){
				cout << "error\n";
			}
			x = (result + 1) % p;
		}
		cout << x << " " << (time(NULL) - tm) << '\n';
	}
    return 0;
}
