#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    vector<int> BFS(int s);  // prints BFS traversal from a given source s
    void DFS(int v);
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
 
vector<int> Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    vector<int> level;
    
    visited[s] = true;
    queue.push_back(s);
    level.push_back(0);
    
    list<int>::iterator i;
    int l; 
    while(!queue.empty()){
        s = queue.front();
        l = level.front();
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                level.push_back(l + 1);
            }
        }
    }
    return level;
}

void Graph::DFSUtil(int v, bool visited[], int level[])
{
    visited[v] = true;
    
    
    
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited, level);
}

void Graph::DFS(int v, int maxlevel)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *level = new int[maxlevel + 1];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i <= maxlevel; i++)
        level[i] = 0;
    
    DFSUtil(v, visited, level);
}

int main(){
	int n, u, v, maxlevel;
	long w;
	scanf("%d", &n);
	vector<long long> weights;
	Graph g(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &w);
		weights.push_back(w);
	}
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &u, &v);
		g.addEdge(u - 1, v - 1);
    	g.addEdge(v - 1, u - 1);		
	}
	vector<int> l = g.BFS(0);
	int levels[MAX];
	maxlevel = 0;
	memset(levels, 0, sizeof levels);
	for(int i = 0; i < n; i++){
		levels[l[i]]++;
		if(maxlevel < l[i])
			maxlevel = l[i];
	}
	
	return 0;
}
