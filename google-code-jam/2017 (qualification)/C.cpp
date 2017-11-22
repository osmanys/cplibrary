#include <bits/stdc++.h>
#define fi "C-large.in"
#define fo "C-large.out"

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t;
    long long n, k, g1, g2;
    bool odd;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	printf("Case #%d: ", i);
    	scanf("%lld %lld", &n, &k);
    	g1 = 1;
    	g2 = 0;
    	while(k > (g1 + g2)){
    		odd = n & 1;
			n >>= 1;
			k -= g1 + g2;
			if(odd)
				g1 += g1 + g2;
			else
				g2 += g1 + g2;
		}
		if(k > g1)
			n--;	
		printf("%lld %lld\n", n / 2, n & 1 ? n / 2 : n / 2 - 1);
	}
    
	return 0;
}
