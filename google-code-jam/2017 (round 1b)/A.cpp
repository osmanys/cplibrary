#include <bits/stdc++.h>
#define fi "A-large.in"
#define fo "A-large.out"

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n, s, maxs;
    long long d, k, maxk;
	long double v, maxv;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		scanf("%lld %d", &d, &n);
		maxv = 0;
		for(int i = 0; i < n; i++){
			scanf("%lld %d", &k, &s);
			v = (long double)(d - k) / s;
			if(maxv < v){
				maxv = v;
				maxk = k;
				maxs = s;
			}
		}
		printf("%.6LF\n", floor(1000000 * (long double)(d * maxs) / (d - maxk)) / 1000000);
	}
    
	return 0;
}
