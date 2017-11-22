#include <bits/stdc++.h>

using namespace std;

int main(){
	int m1, m2, m3;
	scanf("%d %d %d", &m1, &m2, &m3);
	printf("%d", (10 * m1 > 100 ? 100 : 10 * m1) + (10 * m2 > 100 ? 100 : 10 * m2) + (10 * m3 > 100 ? 100 : 10 * m3));
	
	return 0;
}
