#include <bits/stdc++.h>

using namespace std;
long long f[13];

void init()
{
	f[0] = 1;
	for(int i = 1; i < 13; i++){
		f[i] = i * f[i - 1];
	}
}

int main(){
	long a, b, g;
	scanf("%ld %ld", &a, &b);
	init();
	cout << f[min(a,b)];
	return 0;
}
