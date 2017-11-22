#include <bits/stdc++.h>
#define MAX 10000
 
using namespace std;
vector<int> adj[MAX];
bool color[MAX];
int travel[2 * MAX];
int first_time[MAX];
int end_time[MAX];
vector<pair<int, int> > odd;

void DFSUtil(int v, int& turn, bool visited[]){
    visited[v] = true;
    travel[turn] = v;
    first_time[v] = turn;
    vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, ++turn, visited);
    travel[++turn] = v;
    first_time[v] = turn;
}

void dfs(int n){
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int turn = 0;
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            DFSUtil(i, turn, visited);
}
 
int main() {
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	dfs();
    return 0;
}
