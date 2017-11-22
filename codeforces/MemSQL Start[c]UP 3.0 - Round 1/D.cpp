#include <bits/stdc++.h>
#define MAX 200010
#define MOD 1000000007

using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS();    // prints DFS traversal of the complete graph
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
int Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    long d, r = 1;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]){
            d = DFSUtil(*i, visited);
            if(d == -1)
            	return -1;
            else
        }
        else
        	return -1;
    }
}
 
// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

int main(){
	long n, u, v;
	scanf("%ld", &n);
	for(long i = 0; i < n; i++){
		scanf("%ld %ld", &u, &v);
		d[u] = v;
	}
	long l, cur, cpath = 1, p = 0;
	for(long i = 1; i <= 2 * n; i++){
		if(!vis[i] && d[i] && d[i] != i){
			cur = i;
			l = 0;
			while(!vis[cur] && d[cur] && d[cur] != cur){
				vis[cur] = cpath;
				l++;
				cur = d[cur];
			}
			if(vis[cur]){
				if(vis[cur] == cpath){
					p++;
				}
				else if(path[vis[cur]]){
					p += l;
				}
			}
			else if(!d[cur]){
				p += l;
			}
			cpath++;
		}
	}
	long long r = 1;
	for(long i = 1; i <= p; i++)
		r = (r * i) % MOD;
	cout << r;
	return 0;
}
