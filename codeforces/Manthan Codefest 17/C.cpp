#include <bits/stdc++.h>
#define MOD 1000000009
#define MAX 100000

using namespace std;
long up[MAX];
long middle[MAX];
long down[MAX];
long total[MAX][3][12];

class Graph
{
    long V;    // No. of vertices
    list<long> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(long v, bool visited[], long m, long k, int x);  // A function used by DFS
public:
    Graph(long V);   // Constructor
    void addEdge(long v, long w);   // function to add an edge to graph
    void DFS(long v, long m, long k, int x);    // DFS traversal of the vertices reachable from v
};
 
Graph::Graph(long V)
{
    this->V = V;
    adj = new list<long>[V];
}
 
void Graph::addEdge(long v, long w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(long v, bool visited[], long m, long k, int x){
	int ind;
    visited[v] = true;
    if(adj[v].size() == 1){
    	up[v] = m - k;
    	middle[v] = 1;
    	down[v] = k - 1;
    	total[v][0][0] = m - k;
    	total[v][1][1] = 1;
    	total[v][2][0] = k - 1;
	}
	else{
	    list<long>::iterator i;
        up[v] = 1;
        middle[v] = 1;
        down[v] = 1;
	    for (i = adj[v].begin(); i != adj[v].end(); ++i){
	        if (!visited[*i]){
	            DFSUtil(*i, visited, m, k, x);
	            
	            up[v] = (up[v] * (up[*i] + down[*i])) % MOD;
	            middle[v] = (middle[v] * down[*i]) % MOD;
	            down[v] = (down[v] * (up[*i] + middle[*i] + down[*i])) % MOD;
				
	            for(int j = 0; j <= x + 1; j++){
		            for(int k = 0; k <= x + 1; k++){
		            	ind = min(j + k, x + 1);
		            	total[v][0][ind] += (total[v][0][ind] + 1LL * total[*i][0][j] * total[*i][2][k]) % MOD;
		            }	            	
				}
	            for(int j = 0; j <= x + 1; j++){
	            	ind = min(j + 1, x + 1);
	            	total[v][1][ind] += (total[v][1][ind] + 1LL * total[*i][2][j] + 1) % MOD;
				}
	            for(int j = 0; j <= x + 1; j++){
		            for(int k = 0; k <= x + 1; k++){
			            for(int l = 0; l <= x + 1; l++){
			            	ind = min(j + k + l, x + 1);
			            	total[v][2][ind] += (total[v][2][ind] + 1LL * total[*i][0][j] * total[*i][1][k] * total[*i][2][l]) % MOD;
			            }
		            }	            	
				}
	        }
	    }
	}
}

void Graph::DFS(long v, long m, long k, int x){
    bool *visited = new bool[V];
    for (long i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited, m, k, x);
}

int main(){
	int x;
	long n, m, u, v, k;
	scanf("%ld %ld", &n, &m);
	Graph g(n);
	for(long i = 0; i < n - 1; i++){
		scanf("%ld %ld", &u, &v);		
	    g.addEdge(u - 1, v - 1);
	    g.addEdge(v - 1, u - 1);
	}
	scanf("%ld %d", &k, &x);
	g.DFS(0, m, k, x);
	printf("%ld", (1LL * up[0] + middle[0] + down[0] - total[0][0][x + 1] - total[0][1][x + 1] - total[0][2][x + 1]) % MOD);
	return 0;
}
