#include <bits/stdc++.h>

using namespace std;

int main(){
	int q, n, k, x, d, p;
	double s;
	scanf("%d", &q);
	while(q--){
		scanf("%d %d %d %d", &n, &k, &x, &d);
		s = 0;
		while(n--){
			scanf("%d", &p);
			s += max(1.0 * k, 1.0 * p * x / 100);
		}
		printf((s > d) ? "upfront\n" : "fee\n");
	}
	return 0;
}
