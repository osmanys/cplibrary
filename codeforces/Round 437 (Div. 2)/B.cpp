#include <bits/stdc++.h>

using namespace std;

int main(){
	long a;
	cin >> a;
	if(a == 1)
		printf("1 1\n1");
	else
		printf("%ld 2\n1 2", 2 * a - 2);
	return 0;
}
