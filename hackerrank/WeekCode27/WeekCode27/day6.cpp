#include <bits/stdc++.h>
#define MAX_LENGTH 7000

using namespace std;
int n, q, i, j, u, v, result;
int nodes[MAX_LENGTH];
bool visited[MAX_LENGTH];
vector<int> adj[MAX_LENGTH];
int paths[MAX_LENGTH][MAX_LENGTH];
int coprimes[MAX_LENGTH][MAX_LENGTH];

int gcd(int a, int b) {
    int t;
    while(b != 0){
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}

void build(){
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            paths[i][j] = -1;
            coprimes[i][j] = 0;
        }
    }
}

void traverse(int parent, int source, bool visited[]){
    visited[source] = true;
    for(vector<int>::reverse_iterator it = adj[source].rbegin(); it != adj[source].rend(); ++it){
        int a = *it;
        if(!visited[a]){
            coprimes[parent][a] = coprimes[parent][source] + (gcd(nodes[parent], nodes[a]) == 1 ? 1 : 0);
            paths[parent][a] = source;
            traverse(parent, a, visited);
        }
    }
}

int main()
{
    cin >> n >> q;
    for(i = 0; i < n; i++)
        cin >> nodes[i];
    build();
    for(i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            visited[j] = false;
        visited[i] = true;
        for(vector<int>::reverse_iterator it = adj[i].rbegin(); it != adj[i].rend(); ++it){
            int a = *it;
            paths[i][a] = i;
            if(gcd(nodes[i], nodes[a]) == 1)
                coprimes[i][a] = 1;
            traverse(i, a, visited);
        }
    }
    while(q--){
        cin >> u >> v;
        u--;
        v--;
        result = 0;
        while(u != v){
            result += coprimes[u][v];
            u = paths[v][u];
        }
        cout << result << '\n';
    }
}
