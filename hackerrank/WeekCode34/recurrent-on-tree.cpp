#include <bits/stdc++.h>
using namespace std;

const long MAXN = 200005;
const long MOD = 1000000007;
const long MAXF = 1000000;
const int LN = 19;

long N, cur, LVL[MAXN], DP[LN][MAXN], A[MAXN];
long BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN];
long l[MAXN], r[MAXN];
bool VIS[MAXN];
long FIB[MAXF];
vector <long> adjList[MAXN];
vector<struct query> Q;

void loadFib(){
	FIB[0] = 0;FIB[1] = 1;FIB[2] = 1;
	for(long i = 3; i < MAXF; i++){
		FIB[i] = (FIB[i - 1] + FIB[i - 2]) % MOD;
	}
}

long fib(long n){
    if (n < MAXF)
    	return FIB[n];
    long k = (n & 1)? (n + 1) / 2 : n / 2;
    return ((n & 1) ? (1LL * fib(k) * fib(k) + 1LL * fib(k-1) * fib(k-1)) : 1LL * (2 * fib(k-1) + fib(k)) * fib(k)) % MOD; 
}
 
struct query{
	long id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
};

void dfs(){
	long u, par, i, v;
	pair<long, long> s;
	stack<pair<long, long> > stack;
    stack.push(make_pair(1, -1)); 
    while (!stack.empty()){
    	s = stack.top();
        stack.pop();        
    	u = s.first;
    	par = s.second;
    	if(u == -1){
			r[par] = ++cur; ID[cur] = par;
    		continue;
		}
    	stack.push(make_pair(-1, u));
    	
		l[u] = ++cur; 
		ID[cur] = u;
		for (i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
		for (i = 0; i < adjList[u].size(); i++){
			v = adjList[u][i];
			if (v == par) continue;
			LVL[v] = LVL[u] + 1;
			DP[0][v] = u;
			stack.push(make_pair(v, u));
		}
	}
}

inline long lca(long u, long v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (long i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (long i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
 
inline void check(long x, long &res){
	if (VIS[x]){
		--VAL[A[x]];
		res = (res - A[x] + MOD) % MOD;
	}
	else if (!VIS[x]){
		VAL[A[x]]++;		
		res = (res + A[x]) % MOD;
	}
	VIS[x] ^= 1;
}
 
void compute(){
	long curL = Q[0].l, curR = Q[0].l - 1, u, v;	
	long ans = 0, res = 0, M = Q.size();
 
	for (long i = 0; i < M; i++){
 
		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);
 
		u = ID[curL];
		v = ID[curR];
		
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
		
		ans = (ans + (Q[i].l != Q[i].r ? 2 : 1) * fib(res + 1)) % MOD;
 
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
	}
 
	printf("%ld\n", ans);
}
 
int main(){
	long u, v;
 
	scanf("%ld", &N);
	
	for (long i = 1; i < N; i++){
		scanf("%ld %ld", &u, &v);
		/*u = i;
		v = i + 1;*/
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	
	for (long i = 1; i <= N; i++) /*A[i] = 10000 * i;*/scanf("%ld", &A[i]);
	
	DP[0][1] = 1;
	dfs();
	int size = sqrt(cur);

	for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;

	for (long i = 1; i <= N; i++){
		for(long j = i; j <= N; j++){
			u = i;
			v = j;
			struct query q;
			q.lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (q.lc == u) q.l = l[u], q.r = l[v];
			else q.l = r[u], q.r = l[v];
			q.id = i;
			Q.push_back(q);
		}
	}
	
	loadFib();

	sort(Q.begin(), Q.end());
	compute();
	return 0;
}
