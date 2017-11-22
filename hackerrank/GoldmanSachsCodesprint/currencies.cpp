#include <bits/stdc++.h>
#define MAX 20

using namespace std;
int d[MAX][MAX];
unsigned long long _m[MAX][MAX][100];
int _p[MAX][MAX][100];

int main(){
	int n, x, s, f, b;
	long m;
	scanf("%d", &n);
	scanf("%d %d %d %ld", &x, &s, &f, &m);
	srand (time(NULL));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			//scanf("%d", &d[i][j]);
			d[i][j] = rand() % 10 + 1;
	for(int j = 0; j < n; j++)
		d[j][j] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
	for(m = 2; m < 20; m++){
		memset(_m, 0, sizeof _m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				_m[i][j][1] = d[i][j];
		for(int k = 2; k <= m; k++){
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					for(int l = 0; l < n; l++)
						if(_m[i][j][k] < d[i][l] * _m[l][j][k - 1]){
							_m[i][j][k] = d[i][l] * _m[l][j][k - 1];
							_p[i][j][k] = l;
						}
		}
		printf("%d ", m);
		cout << _m[s][f][m] << " ";
		printf("%d ", s);
		b = s;
		for(int k = m; k > 1; k--){
			printf("%d ", _p[b][f][k]);
			b = _p[b][f][k];
			
		}
		printf("%d\n", f);
	}
	return 0;
}
