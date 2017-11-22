#include <bits/stdc++.h>
#define fi "D-small-practice.in"
#define fo "D-small-practice.out"

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, k, c , s, m, n;
    long long result, pp;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	scanf("%d %d %d", &k, &c, &s);
    	printf("Case #%d: ", i);
    	m = (k / c) + (k % c != 0);
		if(s < m)
			printf("%s", "IMPOSSIBLE");
		else
			for(int j = 1; j <= m; j++){
				n = j * c;
				result = n;
				pp = k;
				for(int p = 1; p < c; p++){
					result += (n - p - 1) * pp;
					pp *= k;
				}
				if(result > pp * k)
					printf("large");
				printf("%lld ", result);
			}
		printf("\n");
	}
    
	return 0;
}
