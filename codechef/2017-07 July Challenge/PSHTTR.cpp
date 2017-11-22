#include <bits/stdc++.h>
#define MAX 100001
 
using namespace std;
long bit[2 * MAX];
long ans[MAX];
vector<pair<pair<long, long>, pair<long, long> > > queries;
vector<pair<long, long> > tree[MAX];
bool vis[MAX];
long vis_time[MAX];
long end_time[MAX];
vector<pair<long, long> > travel;
long n, m, tim;

void update(long idx, long val){
    while(idx < 2 * n){
        bit[idx] ^= val;
        idx += idx & -idx;
    }
}

long query(long idx){
    long res = 0;
    while(idx > 0){
        res ^= bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

void solve(){
	long c, res, cur = 0;
	for(long i = 0; i < m; i++){
		c = queries[i].first.first;
		while(cur < 2 * n - 2){
			if(travel[cur].first > c)
				break;
			update(travel[cur].second, travel[cur].first);
			cur++;
		}		
		ans[queries[i].first.second] = query(end_time[queries[i].second.first] - 1) ^ query(end_time[queries[i].second.second] - 1);
	}
}
 
void dfs(long v, long c){
    vis[v] = true;
    vis_time[v] = ++tim;
    if(c)    	       	
    	travel.push_back(make_pair(c, tim));
    vector<pair<long, long> >::iterator it;
    for (it = tree[v].begin(); it != tree[v].end(); it++)
        if (!vis[(*it).first])
            dfs((*it).first, (*it).second);
    end_time[v] = ++tim;
    if(c)    	       	
    	travel.push_back(make_pair(c, tim));
}

void init(){
	queries.clear();
	travel.clear();
	memset(vis, false, sizeof vis);
	memset(bit, 0, sizeof bit);
	for(long i = 0; i < MAX; i++)
		tree[i].clear();
	tim = 0;
}

int main() {
	int t;
	scanf("%d", &t);
	long u, v, c;
	while(t--){
		init();
		scanf("%ld", &n);
		for(long i = 0; i < n - 1; i++){
			scanf("%ld %ld %ld", &u, &v, &c);
		    tree[u - 1].push_back(make_pair(v - 1, c));
		    tree[v - 1].push_back(make_pair(u - 1, c));
		}
		dfs(0, 0);
		sort(travel.begin(), travel.end());
		scanf("%ld", &m);
		for(long i = 0; i < m; i++){
			scanf("%ld %ld %ld", &u, &v, &c);
			queries.push_back(make_pair(make_pair(c, i), make_pair(u - 1, v - 1)));
		}
		sort(queries.begin(), queries.end());
		solve();
		for(long i = 0; i < m; i++)
			printf("%ld\n", ans[i]);
	}
    return 0;
}
