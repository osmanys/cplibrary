#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	long m, x, y;
	scanf("%d", &t);
	while(t--){
		scanf("%ld", &m);
		x = m / 3;
		y = 2 * (m / 3);
		if(m % 3)
			x++;
		if(m % 3 == 2)
			y++;
		printf("%ld %ld\n", x, y);
	}
    return 0;
}
