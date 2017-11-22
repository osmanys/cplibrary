#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	long n;
	scanf("%d", &t);
	while(t--){
		scanf("%ld", &n);
		for(long i = 1; i < n / 2; i++)
			printf("%ld %ld ", 2 * i, 2 * i - 1);
		if(n & 1){
			printf("%ld %ld %ld\n", n - 1, n, n - 2);
		}
		else{
			printf("%ld %ld\n", n, n - 1);			
		}
	}
    return 0;
}
