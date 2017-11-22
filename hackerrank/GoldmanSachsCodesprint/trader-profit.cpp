#include <bits/stdc++.h>
#define MAXN 31
#define MAXK 11

using namespace std;
int a[MAXN];
int d[MAXN][MAXK];

int main(){
	int q, k, n, m;
	scanf("%d", &q);
	while(q--){
		memset(d, 0, sizeof d);
		scanf("%d", &k);
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int j = 1; j < MAXK; j++){
			for(int i = 0; i < n; i++){
				m = 0;
				for(int l = i; l < n; l++){
					if(m < a[l] - a[i] + d[l + 1][j - 1])
						m = a[l] - a[i] + d[l + 1][j - 1];
				}
				d[i][j] = m;
			}
		}
		printf("%d\n", d[0][k]);
	}	
	return 0;
}
