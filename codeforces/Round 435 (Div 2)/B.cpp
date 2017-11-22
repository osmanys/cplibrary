#include <bits/stdc++.h>

using namespace std;

class Graph
{
    long V;    // No. of vertices
    list<long> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(long v, bool visited[], long &w, long &b, bool white);  // A function used by DFS
public:
    Graph(long V);   // Constructor
    void addEdge(long v, long w);   // function to add an edge to graph
    void DFS(long v, long &w, long &b);    // DFS traversal of the vertices reachable from v
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
 
void Graph::DFSUtil(long v, bool visited[], long &w, long &b, bool white)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    if(white)
    	w++;
    else
    	b++;
 
    // Recur for all the vertices adjacent to this vertex
    list<long>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited, w, b, !white);
}
 
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil()
void Graph::DFS(long v, long &w, long &b)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (long i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited, w, b, true);
}

int main(){
	long n, u, v;
	scanf("%ld", &n);
	Graph graph(n);
	for(long i = 1; i < n; i++){
		scanf("%ld %ld", &u, &v);
		graph.addEdge(u - 1, v - 1);
		graph.addEdge(v - 1, u - 1);
	}
	long w = 0, b = 0;
	graph.DFS(0, w, b);
	cout << (1LL * w * b - n + 1);
	return 0;
}
