#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
vector<long> adj[MAX];
int c[MAX];
long b[MAX], w[MAX], cmax, cmin, vmax, vmin, p[MAX];
vector<long> r;

void dfs(long v, long &_max, long &_min){
    _max = c[v], _min = c[v];
	long pmax, pmin;
    vector<long>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
    	if(p[v] != *i){
	    	p[*i] = v;
	        dfs(*i, pmax, pmin);
	        _max += (pmax > 0 ? pmax : 0);
	        _min += (pmin < 0 ? pmin : 0);
	    }
    }
    b[v] = _max;
    if(vmax < _max){
    	vmax = _max;
    	cmax = v;
	}
    w[v] = _min;
    if(vmin > _min){
    	vmin = _min;
    	cmin = v;
	}
}

void loadr(long v, bool tb){
	r.push_back(v);
    vector<long>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
    	if(p[v] != *i && ((tb && b[*i] > 0) || (!tb && w[*i] < 0)))
        	loadr(*i, tb);
    }
}

int main(){
	int t;
	long n, u, v;
	cin >> n;
	for(long i = 0; i < n; i++){
		scanf("%d", &t);
		c[i] = t ? 1 : -1;
	}
	for(long i = 0; i < n - 1; i++){
		scanf("%ld %ld", &u, &v);
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	cmax = -1; cmin = -1; vmax = 0; vmin = 0;
	long _max, _min;
    dfs(0, _max, _min);
    loadr((vmax > -vmin) ? cmax : cmin, vmax > -vmin);	
	printf("%ld\n", max(vmax, -vmin));
	printf("%ld\n", r.size());
	for(vector<long>::iterator it = r.begin(); it != r.end(); it++)
		printf("%ld ", *it + 1);
	return 0;
}
