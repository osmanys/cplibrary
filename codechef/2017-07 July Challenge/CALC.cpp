#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	long t, n, b, y;
	scanf("%ld", &t);
	while(t--){
		scanf("%ld %ld", &n, &b);
		y = n / (2 * b);
		if(b <= n % (2 * b))
			y++;
		cout << (y * (n - 1LL * y * b)) << "\n";
	}	
    return 0;
}
