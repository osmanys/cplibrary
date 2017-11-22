#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;
long g[MAX];
vector<long> adj[MAX];
vector<pair<long, long> > difq;
vector<long> graph[MAX];
 
void groupingUtil(long v, bool visited[], long group){
    visited[v] = true;
    g[v] = group;
    vector<long>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            groupingUtil(*i, visited, group);
}

long grouping(long V){
    bool *visited = new bool[V];
    for(long i = 0; i < V; i++)
        visited[i] = false;
    long group = 0;
    for(long i = 0; i < V; i++)
        if (!visited[i]){
            groupingUtil(i, visited, group);
	        group++;
	    }
	return group;
}
 
bool hocUtil(long v, bool visited[], bool color[], bool white){
    visited[v] = true;
    color[v] = white;
    vector<long>::iterator i;
    for(i = graph[v].begin(); i != graph[v].end(); ++i){
        if(!visited[*i]){
            if(hocUtil(*i, visited, color, !white))
            	return true;
        }
        else if(white == color[*i])
        	return true;
	}
	return false;
}

bool hasOddCycle(long V){
    bool *visited = new bool[V];
    bool *color = new bool[V];
    for(long i = 0; i < V; i++)
        visited[i] = false;
    for(long i = 0; i < V; i++)
        if (!visited[i] && hocUtil(i, visited, color, true))
        	return true;
	return false;
}
 
int main() {
	long t, n, q, i, j, gp;
	int v;
	scanf("%ld", &t);
	while(t--){
		scanf("%ld %ld", &n, &q);
		difq.clear();
		for(long k = 0; k < n; k++)
			adj[k].clear();
		for(long k = 0; k < q; k++){
			scanf("%ld %ld %d", &i, &j, &v);
			if(!v){
				adj[i - 1].push_back(j - 1);
				adj[j - 1].push_back(i - 1);
			}
			else
				difq.push_back(make_pair(i - 1, j - 1));
		}
		gp = grouping(n);
		for(long k = 0; k < gp; k++)
			graph[k].clear();
		for(vector<pair<long, long> >::iterator it = difq.begin(); it != difq.end(); it++){
			graph[g[(*it).first]].push_back(g[(*it).second]);
			graph[g[(*it).second]].push_back(g[(*it).first]);
		}
		if(hasOddCycle(gp))
			printf("no\n");
		else
			printf("yes\n");
	}
    return 0;
}
