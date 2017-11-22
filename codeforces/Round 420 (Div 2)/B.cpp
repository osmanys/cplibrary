#include <bits/stdc++.h>

using namespace std;

int main(){
	long long count, max = 0;
	long y, x;
	int m, b;
	scanf("%d %d", &m, &b);
	for(y = 0; y <= b; y++){
		x = 1L * m * b - 1L * m * y;
		count = 1LL * (y + 1) * (x + 1) * (x + y) / 2;
		if(max < count)
			max = count;
	}
	cout << max;
	return 0;
}
