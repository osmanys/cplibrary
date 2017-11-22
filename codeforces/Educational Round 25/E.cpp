#include <bits/stdc++.h>

using namespace std;

class Graph
{
    long V;    // No. of vertices
    list<long> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(long V);  // Constructor
    void addEdge(long v, long w); // function to add an edge to graph
    void BFS(long s);  // prints BFS traversal from a given source s
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
 
long r Graph::BFS(long s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(long i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    priority_queue<long> queue;
        
	long r[V];
    long c = 0;
 	
	for(long i = 0; i < V; i++){
		if(!visited[i]){
		    // Mark the current node as visited and enqueue it
		    visited[s] = true;
		    queue.push(s);
		 
		    // 'i' will be used to get all adjacent vertices of a vertex
		    list<long>::iterator i;
		 
		    while(queue.size())
		    {
		        // Dequeue a vertex from queue and print it
		        s = queue.top();
		        r[s] = ++c;
		        //cout << s << " ";
		        queue.pop();
		 
		        // Get all adjacent vertices of the dequeued vertex s
		        // If a adjacent has not been visited, then mark it visited
		        // and enqueue it
		        for(i = adj[s].begin(); i != adj[s].end(); ++i)
		        {
		            if(!visited[*i])
		            {
		                visited[*i] = true;
		                queue.push(*i);
		            }
		        }
		    }
		}
	}
	return r;
}

int main(){
	long n, m, u, v;
	scanf("%ld %ld", &n, &m);
		Graph g(n);
	for(long i = 0; i < m; i++){
		scanf("%ld %ld", &u, &v);
    	g.addEdge(u - 1, v - 1);
	}
	long t = 0;
	while(true){
		g.BFS(t);	
		for(long i = 0; i < n; i++)
			if(!r[i])
				break;
		if
	}
	for(long i = 0; i < n; i++)
		printf("%ld ", r[i]);
	return 0;
}
