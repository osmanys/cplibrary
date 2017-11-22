#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	long n, d, r, m;
	scanf("%d", &t);
	while(t--){
		scanf("%ld", &n);
		m = 100000;
		for(long i = 1; i <= n; i++){
			scanf("%ld", &d);
			if(m > d){
				m = d;
				r = i;
			}
		}
		printf("%ld\n", r);
	}	
    return 0;
}
