#include <bits/stdc++.h>
#define MAX 10
 
using namespace std;
int pf[MAX][MAX];
int pt[MAX][MAX];

pair<int, int> solve(int n, int m, bool visited[MAX][MAX], int x, int y){
	visited[x][y] = true;
	if((x == n - 1) && (y == m - 1)){
		visited[x][y] = false;
		return make_pair(pf[x][y], pt[x][y]);
	}
	int mf = INT_MAX, mt = INT_MAX;
	pair<int, int> p;
	if(x < n - 1 && !visited[x + 1][y]){
		p = solve(n, m, visited, x + 1, y);
		if(p.first < mf || (p.first == mf && p.second < mt)){
			mf = p.first;
			mt = p.second;
		}
	}
	if(y < n - 1 && !visited[x][y + 1]){
		p = solve(n, m, visited, x, y + 1);
		if(p.first < mf || (p.first == mf && p.second < mt)){
			mf = p.first;
			mt = p.second;
		}
	}
	visited[x][y] = false;
	return make_pair(pf[x][y] + mf, pt[x][y] + mt);
}

pair<int, int> calc(int n, int m){
	bool visited[MAX][MAX];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			visited[i][j] = false;
	return solve(n, m, visited, 0, 0);
}
 
int main() {
	int t, n, m;
	pair<int, int> r;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &pf[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &pt[i][j]);
		r = calc(n, m);
		printf("%d %d\n", r.first, r.second);
	}
    return 0;
}
