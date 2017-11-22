#include <bits/stdc++.h>
#define MAX 3001
#define MOD 1000000007

using namespace std;
long long data[MAX][MAX];

int main(){
	int q, n, k, c;
	long long r;
	scanf("%d", &q);
	memset(data, 0, sizeof data);
	data[2][1] = 2;
	for(int t = 3; t <= 3000; t++){
		for(int f = (t - 1) / 2; f < t - 1; f++){
			c = 2 * f - t + 2;
			data[t][f] += (c * data[t - 1][f]) % MOD;
			data[t][f + 1] += ((t - c) * data[t - 1][f]) % MOD;
		}
	}
	while(q--){
		scanf("%d %d", &n, &k);
		r = 0;
		for(int i = k; i < n; i++)
			r = (r + data[n][i]) % MOD;
		printf("%lld\n", r);
	}
	
	return 0;
}
