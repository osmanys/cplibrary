#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;
vector<long> adj[MAX];
 
long dfs_util(long v, int marked[], bool visited[], bool endvisited[], long& mchilds){
	visited[v] = true;
    if(adj[v].size() == 1 && v){
    	marked[v] = 3;
    	mchilds = 0;
		endvisited[v] = true;
    	return 1;
	}
	long r = 0;
    long gchilds = 0;
    vector<long>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
    	if(!visited[*i]){
	        r += dfs_util(*i, marked, visited, endvisited, mchilds);
	        gchilds += mchilds;
	    }
    }
    long m[4] = {0, 0, 0, 0};
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    	if(endvisited[*i])
    		m[marked[*i]]++;
    if(!(m[2] + m[3]) || m[1]){
    	marked[v] = 2;
    	r++;
	}
	else if((m[2] + m[3] == 1) || m[3]){
		marked[v] = 1;
	}
	else{
		marked[v] = 0;
	}
	mchilds = m[2] + m[3];
	endvisited[v] = true;
	return r;
}
 
long solve(long v, long n){
    if(n == 1)
    	return -1;
    int *marked = new int[n];
    bool *visited = new bool[n];
    bool *endvisited = new bool[n];
	for(long i = 0; i < n; i++){
		visited[i] = false;
		endvisited[i] = false;
	}
    long mchilds;
    long r = dfs_util(v, marked, visited, endvisited, mchilds);
	if(marked[0] == 1){
		marked[0] = 2;
		r++;
	}
	/*for(long i = 0; i < n; i++)
		if(marked[i] == 2 || marked[i] == 3)
			printf("%ld ", i + 1);
	printf("\n");*/
    return r;
}
 
int main() {
	int t;
	long n, u, v;
	scanf("%d", &t);
	while(t--){
		scanf("%ld", &n);
		for(long i = 0; i < n; i++)
			adj[i].clear();
		for(long i = 0; i < n - 1; i++){
			scanf("%ld %ld", &u, &v);			
    		adj[u - 1].push_back(v - 1);			
    		adj[v - 1].push_back(u - 1);
		}
		printf("%ld\n", solve(0, n));
	}
    return 0;
}
