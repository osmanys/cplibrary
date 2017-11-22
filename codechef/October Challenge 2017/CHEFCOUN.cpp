#include <bits/stdc++.h>
#define MAX (1LL << 33)
#define L 100000
 
using namespace std;
 
int main() {
	int t;
	long n, x, y, y2, y3, r;
	cin >> t;
	while(t--){
		cin >> n;
		y = MAX / (n + 1);
		x = MAX % (n + 1);
		y2 = y + (x & 1);
		y3 = (y + x / 2) > L ? L : (y + x / 2);
		r = (y + x / 2) > L ? 2 * ((y + x / 2) % L) : 0;
		for(long i = 0; i < n - 2; i++)
			printf("%ld ", y + (i < r));
		printf("%ld ", y2);
		printf("%ld\n", y3);
	}
    return 0;
}
