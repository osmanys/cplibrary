#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, x2;
	int a;
	scanf("%ld %d", &n, &a);
	x2 = 2 + n * a / 180;
	if(x2 == 2 || abs(n * a - 180 * (x2 - 2)) > abs(n * a - 180 * (x2 - 1))){
		x2++;
	}
	printf("2 1 %ld", x2 > n ? n : x2);
	return 0;
}
