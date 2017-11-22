#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, k;
	scanf("%ld %ld", &n, &k);
	printf("%ld\n", 2 * ((n - 1) / k) + (((n - 1) % k > 1) ? 2 : (n - 1) % k));
	for(long i = 2; i <= n; i++)
		printf("%ld %ld\n", i, (i - k <= 1) ? 1 : i - k);
	return 0;
}
