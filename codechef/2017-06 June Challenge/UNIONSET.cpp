#include <bits/stdc++.h>
#define MAX 2500

using namespace std;
int l[MAX];
int d[MAX][MAX];

int main(){
	long r;
	int t, n, k, ci, cj, v;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i++){
			scanf("%d", &l[i]);
			for(int j = 0; j < l[i]; j++)
				scanf("%d", &d[i][j]);
			sort(d[i], d[i] + l[i]);
		}
		r = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				ci = 0;cj = 0;v = 1;
				for(; v <= k; v++){
					if((ci >= l[i] || d[i][ci] != v) && (cj >= l[j] || d[j][cj] != v))
						break;
					if(d[i][ci] == v)
						ci++;
					if(d[j][cj] == v)
						cj++;
				}
				if(v > k)
					r++;
			}
		}
		printf("%ld\n", r);
	}
	return 0;
}
