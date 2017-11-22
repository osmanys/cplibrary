#include <bits/stdc++.h>
#define MAX 100001
 
using namespace std;
long d[MAX];
vector<pair<long, long> > edges;
long mark[MAX];
bool visited[MAX];
 
int main() {
	int t;
	long n, m, u, v, level, mew, c;
	bool valid;
	scanf("%d", &t);
	while(t--){
		scanf("%ld %ld", &n, &m);
		memset(d, 0, sizeof(long) * (n + 1));
		memset(mark, 0, sizeof(long) * (n + 1));
		memset(visited, false, sizeof(bool) * (n + 1));
		edges.clear();
		for(long i = 0; i < m; i++){
			scanf("%ld %ld", &u, &v);
			edges.push_back(make_pair(u, v));
		}
		sort(edges.begin(), edges.end());
		valid = true;
		level = 0;
		mew = 0;
		c = 0;
		u = 0;
		v = 0;
		for(vector<pair<long, long> >::iterator it = edges.begin(); it != edges.end(); it++){			
			/*if(u == (*it).first && v == (*it).second)
				continue;*/
			u = (*it).first;
			v = (*it).second;
			visited[u] = true;
			if(!u){
				d[v] = ++c;
				mark[c]++;
			}
			else{
				if(!level)
					level = 1;
				if(level != u){
					if(mew){
						d[mew] = d[level];
						mark[d[mew]]++;
						mew = 0;
					}
					level++;
					if(level != u || mark[d[u]] != level){
						valid = false;
						break;
					}
				}
				if(d[v]){
					if(mark[d[v]] != level){
						valid = false;
						break;
					}
					mark[d[v]]++;
				}
				else{
					if(mew){
						valid = false;
						break;
					}
					mew = v;
				}
			}
		}
		if(mew)
			d[mew] = d[level];
		for(long i = 0; i < n; i++)
			if(!visited[i]){
				valid = false;
				break;
			}
		if(!valid || level != n - 1)
			printf("-1\n");
		else {
			for(long i = 1; i <= n; i++)
				printf("%ld ", d[i]);
			printf("\n");
		}
	}
    return 0;
}

