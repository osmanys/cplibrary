#include <bits/stdc++.h>

using namespace std;

bool lucky_ticket(long n){
	return (((n / 1) % 10) + ((n / 10) % 10) + ((n / 100) % 10)) == (((n / 1000) % 10) + ((n / 10000) % 10) + ((n / 100000) % 10));
}

int main(){
	long n;
	scanf("%ld", &n);
	while(!lucky_ticket(++n));
	printf("%ld", n);
	return 0;
}
