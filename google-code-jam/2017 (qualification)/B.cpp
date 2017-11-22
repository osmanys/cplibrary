#include <bits/stdc++.h>
#define fi "B.in"
#define fo "B.out"

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, a, d;
    long long n, div, last;
    bool search;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	printf("Case #%d: ", i);
    	scanf("%lld", &n);
    	a = 10;
    	div = 1;
    	search = false;
    	last = -1;
    	while(n / div){
    		d = (n / div) % 10;
    		if(a < d)
    			search = true;
    		else if(search && (a > d)){
    			search = false;
    			last = div / 10;
			}
			a = d;
			if(n / div < 10){
				if(search)
					last = div;
				break;
			}
			div *= 10;
		}
		if(last > -1)
			n = (n / last) * last - 1;
		printf("%lld\n", n);
	}
    
	return 0;
}
