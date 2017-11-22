#include <bits/stdc++.h>
#define fi "C.in"
#define fo "C.out"
#define MAX 100
#define INF 99999

using namespace std;
int graph[MAX][MAX], dist[MAX][MAX];

void FloydWarshall(int V){
    int i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
    int t, n, m, u, v, d;
    long p, d1, tot;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		scanf("%d %d %ld", &n, &m, &p);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				graph[i][j] = INF;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &d);
			graph[u - 1][v - 1] = d;
			graph[v - 1][u - 1] = d;
		}
		FloydWarshall(n);
		for(int i = 0; i < n; i++)
			dist[i][i] = 0;
		d1 = 0;
		for(int i = 0; i < n; i++)
			d1 += dist[0][i];
		tot = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				tot += dist[i][j];
		if(p == 1)
			printf("%f\n", d1 / (float)(n - 1));
		else
			printf("%f\n", (1LL * n * (n - 2) * d1 + (1LL * (n - 1) * (p - 1) + 1) * tot) / ((float)(n - 1) * (n - 1) * n));
	}    
	return 0;
}
