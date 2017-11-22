#include <bits/stdc++.h>
#define MX 1000

using namespace std;
long C[MX][MX];
long H[MX][MX];

long minKey(long key[], bool mstSet[]){
   long min = LONG_MAX, min_index; 
   for (int v = 0; v < V; v++)
     if (!mstSet[v] && key[v] < min)
         min = key[v], min_index = v; 
   return min_index;
}

void primMST(int V){
	int count[V];
	int parent[V];
	long key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++){
		key[i] = H[i][1];
		mstSet[i] = false;
		parent[i] = -1;
		count[i] = 0;
	}
	for(int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		count[u]++;
		if(parent[u] != -1)
			count[parent[u]]++;
		for(int v = 0; v < V; v++)
			if(!mstSet[v] && (C[u][v] + H[u][count[u] + 1] + H[v][count[v] + 1] < key[v])){
				parent[v] = u;
				key[v] = C[u][v] + H[u][1] + H[v][1];
		}
	}
}

unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int n;
		long Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for(int i = 0; i < n; i++){
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++)
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
		}		
		for(int i = 0; i < n; i++){
			scanf("%llu %llu", &s[0], &s[1]);
			for(int j = 0; j < n; j++)
				H[i][j] = xorshift128plus() % (Hmax + 1);
		}		
		// solve here
	}	
	return 0;
}
