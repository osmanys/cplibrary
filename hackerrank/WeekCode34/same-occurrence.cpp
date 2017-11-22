#include <bits/stdc++.h>
#define MAX 8000
#define MAXQ 500000
#define MAXV 1000000001

using namespace std;
long d[MAX];
map<long, vector<int> > pos;
vector<pair<pair<long long, long>, pair<long, long> > > queries;
long ans[MAXQ];

void solve(int n, int q){
	long u = -1, v = -1, r;
	int count, cur;
	pair<int, int> c;
	map<int, int> eq;
	priority_queue<pair<int, int> > pi, pc;
	sort(queries.begin(), queries.end());
	for(int i = 0; i < q; i++){
		if(u == queries[i].second.first && v == queries[i].second.second){
			ans[queries[i].first.second] = ans[queries[i - 1].first.second];
			continue;
		}
		else if(u == queries[i].second.first){
			v = queries[i].second.second;
			pc = pi;
			for(vector<int>::iterator it = pos[v].begin(); it != pos[v].end(); it++)
				pc.push(make_pair(*it, -1));
		}
		else{
			u = queries[i].second.first;
			v = queries[i].second.second;
			for(vector<int>::iterator it = pos[u].begin(); it != pos[u].end(); it++)
				pi.push(make_pair(*it, 1));
			pc = pi;
			for(vector<int>::iterator it = pos[v].begin(); it != pos[v].end(); it++)
				pc.push(make_pair(*it, -1));			
		}
		count = 0, cur = 0;
		eq.clear();
		while(!pi.empty()){
			c = p.top();
			p.pop();
			
			eq[count] += c.first - cur;
			count += c.second;
			cur = c.first;
		}
		eq[count] += n - cur;
		r = (eq.find(0) == eq.end()) ? 0 : eq[0];
		for(map<int, int>::iterator it = eq.begin(); it != eq.end(); it++)
			r += 1L * (*it).second * ((*it).second - 1) / 2;
		ans[queries[i].first.second] = r;
	}
}

int main(){
	int n, q;
	long u, v;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%ld", &d[i]);
		//d[i] = i + 1;
		pos[d[i]].push_back(i); 
	}
	for(int i = 0; i < q; i++){
		scanf("%ld %ld", &u, &v);
		queries.push_back(make_pair(make_pair(min(u, v) * MAXV + max(u, v), i), make_pair(min(u, v), max(u, v))));
	}
	solve(n, q);
	for(int i = 0; i < q; i++)
		printf("%ld\n", ans[i]);
	return 0;
}
