#include <bits/stdc++.h>
#define MAXN 200000
#define LEVELS 18
#define MAX (1 << LEVELS)
 
using namespace std;
vector<long> g[MAXN];
long long d[MAXN];
long long h[MAX];
vector<long long> r[MAX];

void dfs(long v, bool visited[], long l){
    visited[v] = true;
    h[l] ^= d[v];
    vector<long>::iterator i;
    for (i = g[v].begin(); i != g[v].end(); ++i)
        if (!visited[*i])
            dfs(*i, visited, l + 1);
}

void solve(long n){
    bool *visited = new bool[n];
    for (long i = 0; i < n; i++)
        visited[i] = false;
    dfs(0, visited, 0);
    for(long i = 0; i < MAX; i++)
    	r[0].push_back(h[i]);
    long shift = 1, index;
    long long vl;
	for(long l = 0; l < LEVELS; l++){
		index = 0;
		while(index < MAX){	
			vl = r[0][index] ^ r[0][index + shift];
			r[1 << l].push_back(vl);
			index += 2 * shift;
		}
		for(long sl = 0; sl < l; sl++){
			for(long i = 0; i < (1 << sl); i++){
				index = 0;
				while(index < MAX){
					vl = r[(1 << sl) + i][index / (1 << (sl + 1))] ^ r[(1 << sl) + i][(index + shift) / (1 << (sl + 1))];
					r[(1 << l) + (1 << sl) + i].push_back(vl);
					index += 2 * shift;
				}
			}
		}
		shift *= 2;
	}
}
 
int main() {
	long n, q, u, v;
	long long t;
	scanf("%ld %ld", &n, &q);
	for(long i = 1; i < n; i++){
		scanf("%ld %ld", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(long i = 0; i < n; i++)
		scanf("%lld", &d[i]);
	solve(n);
	for(long i = 0; i < q; i++){
		scanf("%lld", &t);
		printf("%ld\n", !(t % MAX) ? h[0] : r[MAX - t % MAX][0]);
	}
    return 0;
}
