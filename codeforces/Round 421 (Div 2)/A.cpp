#include <bits/stdc++.h>

using namespace std;

int main(){
	int c, v0, v1, a, l, count = 0;
	long current = 0;
	scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);
	do{
		current += (v0 + 1L * count * a > v1) ? v1 : (v0 + 1L * count * a);
		count++;
		if(current >= c)
			break;
		current -= l;
	} while(current < c);
	printf("%d", count);
	return 0;
}
