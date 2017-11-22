#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;
long c[MAX][3];
long sz[MAX];
vector<long> d[MAX];
long ac[MAX];

long mind(long v1, long v2, long c){
	v1 = (sz[c] + v1 - 1) % sz[c];
	v2 = (sz[c] + v2 - 1) % sz[c];
	if(v1 > v2)
		swap(v1, v2);
	return min(d[c][v2] - d[c][v1], d[c][sz[c] - 1] - d[c][v2] + d[c][v1]);
}

long cdist(long c1, long c2, long n){
	return (c1 > c2 ? ac[n - 1] : 0) + ac[c2] - ac[c1] - mind(c[c2][0], c[(n + c2 - 1) % n][1], c2) - c[c2][2] + c[c1][2];
}
 
int main() {
	int t;
	cin >> t;
	long n, q, r1, r2, v1, c1, v2, c2;
	while(t--){
		scanf("%ld %ld", &n, &q);
		for(long i = 0; i < n; i++){
			scanf("%ld", &sz[i]);
			d[i].clear();
			d[i].reserve(sz[i]);
			for(long j = 0; j < sz[i]; j++)
				scanf("%ld", &d[i][j]);
		}
		for(long i = 0; i < n; i++){
			scanf("%ld %ld %ld", &c[i][0], &c[i][1], &c[i][2]);
			c[i][0]--;c[i][1]--;
		}
		for(long i = 0; i < n; i++)
			for(long j = 1; j < sz[i]; j++)
				d[i][j] += d[i][j - 1];
		ac[0] = mind(c[0][0], c[n - 1][1], 0) + c[0][2];
		for(long i = 1; i < n; i++)
			ac[i] = ac[i - 1] + mind(c[i][0], c[(n + i - 1) % n][1], i) + c[i][2];
		for(long i = 0; i < q; i++){
			scanf("%ld %ld %ld %ld", &v1, &c1, &v2, &c2);
			v1--;c1--;v2--;c2--;		
			if(c1 > c2){
				swap(c1, c2);
				swap(v1, v2);
			}
			r1 = mind(v1, c[c1][0], c1) + cdist(c1, c2, n) + mind(v2, c[c2 - 1][1], c2);
			r2 = mind(v1, c[(n + c1 - 1) % n][1], c1) + cdist(c2, c1, n) + mind(v2, c[c2][0], c2);
			printf("%ld\n", min(r1, r2));
		}
	}
    return 0;
}

