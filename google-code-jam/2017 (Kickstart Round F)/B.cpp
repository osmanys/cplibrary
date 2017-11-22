#include <bits/stdc++.h>
#define fi "B.in"
#define fo "B.out"
#define MAX 10000

using namespace std;
long s[MAX];
long long d[MAX];

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
    int t, n, pos, p;
    long e;
	long long m;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		scanf("%ld %d", &e, &n);
		for(int i = 0; i < n; i++)
			scanf("%ld", &s[i]);
		sort(s, s + n);
		d[0] = s[0];
		for(int i = 1; i < n; i++)
			d[i] = d[i - 1] + s[i];
		m = e;
		p = 0;
		for(int i = n - 1; i >= 0; i--){
			pos = lower_bound(d, d + n, m) - d;
			if(pos < n - i)
				break;
			if(p < pos - n + i + 1)
				p = pos - n + i + 1;
			m += s[i];
		}
		printf("%d\n", p);			
	}
    
	return 0;
}
