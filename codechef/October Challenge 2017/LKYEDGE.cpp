#include <bits/stdc++.h>
#define MAXV 10000
#define MAXE 5000
 
using namespace std;
long d[MAXE];

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void dfs(int v){
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}
 
int main() {
	int t, m;
	long u, v;
	cin >> t;
	while(t--){
		cin >> m;
		vector<pair<long, int> > adj[MAXV];
		for(int i = 0; i < m; i++){
			scanf("%ld %ld", &u, &v);
			u--;v--;
			adj[u].push_back(make_pair(v, i));
			adj[u].push_back(make_pair(v, i));
		}
		memset(d, 0, sizeof d);
		for(int i = 0; i < m; i++){
			for(int j = i + 2; j < m; j++){
				dfs(adj, i, j);
			}
		}
		for(int i = 0; i < m; i++)
			printf("%ld ", d[i]);
		printf("\n");
	}
    return 0;
}
