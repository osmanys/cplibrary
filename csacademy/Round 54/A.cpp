#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int d[MAX];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	sort(d, d + n);
	long r = 0;
	for(int i = 0; i < k; i++)
		r += d[i];
	cout << (r / 100 + (r % 100 > 0));
	return 0;
}
