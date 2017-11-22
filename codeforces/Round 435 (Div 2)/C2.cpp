#include <bits/stdc++.h>
#define L (1L << 17)

using namespace std;

int main(){
	long n, x;
	scanf("%ld %ld", &n, &x);
	if(n == 1)
		printf("YES\n%ld", x);
	else if(n == 2){
		if(!x)
			printf("NO");
		else
			printf("YES\n%ld %ld", L, L ^ x);		
	}
	else{
		long t = 0, i = 1;
		printf("YES\n");
		for(; i < n - 2; i++){
			printf("%ld ", i);
			t ^= i;
		}
		if((t ^ i) == x){
			printf("%ld ", L ^ t);
			printf("%ld ", L ^ x);
			printf("%ld", 0);			
		}
		else{
			printf("%ld ", i);
			printf("%ld ", L ^ t ^ i);
			printf("%ld", L ^ x);
		}
	}
	return 0;
}
