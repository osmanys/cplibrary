#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int g[MAX][MAX];
int _minr[MAX];
int _minc[MAX];

int main(){
	int n, m, del;
	long total;
	vector<string> c;
	vector<int> v;
	scanf("%d %d", &n, &m);
	memset(_minr, -1, sizeof _minr);
	memset(_minc, -1, sizeof _minc);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &g[i][j]);
			if(_minr[i] == -1 || _minr[i] > g[i][j])
				_minr[i] = g[i][j];
			if(_minc[j] == -1 || _minc[j] > g[i][j])
				_minc[j] = g[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		del = INT_MAX;
		for(int j = 0; j < m; j++){
			if(g[i][j] - _minc[j] < del)
				del = g[i][j] - _minc[j];
		}
		if(del > _minr[i]){
			printf("-1");
			return 0;
		}
		for(int j = 0; j < del; j++){
			c.push_back("row");
			v.push_back(i + 1);
		}
		_minr[i] -= del;
		for(int j = 0; j < m; j++){
			g[i][j] -= del;
			if(_minc[j] > g[i][j])
				_minc[j] = g[i][j];
		}
	}
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			g[i][j] -= _minc[j];
			if(_minr[i] > g[i][j])
				_minr[i] = g[i][j];
		}
		for(int i = 0; i < _minc[j]; i++){
			c.push_back("col");
			v.push_back(j + 1);
		}
	}
	total = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			total += g[i][j] - _minr[i];
		}
		for(int j = 0; j < _minr[i]; j++){
			c.push_back("row");
			v.push_back(i + 1);
		}
	}
	if(total){
		printf("-1");
	}
	else{
		total = c.size();
		printf("%ld\n", total);
		for(int i = 0; i < total; i++){
			printf("%s %d\n", c[i].c_str(), v[i]);
		}
	}
	return 0;
}
