#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t, x;
	long u, v;
	scanf("%d", &t);
	while(t--){
		scanf("%ld %ld %d", &u, &v, &x);
		printf("%.10f\n", (double) x / (u + v));
	}
    return 0;
}
