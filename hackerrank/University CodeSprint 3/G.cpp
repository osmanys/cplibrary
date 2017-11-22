#include <bits/stdc++.h>
#define MAX 200001
#define C 1000001

using namespace std;
long edges[MAX][3];
vector<long> adj[MAX];
vector<long> childs[MAX];
long long pColor[C];
long long BITree[C];
long _count[MAX];
long n;

long long getSum(long index){
    long long sum = 0;
    index = index + 1;
    while (index > 0){
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(long index, long long val){
    index = index + 1;
    while (index <= C){
       BITree[index] += val;
       index += index & (-index);
    }
}
 
struct subset{
    long parent;
    long rank;
};
struct subset subsets[MAX];

long find(long i){
    if (subsets[i].parent != i){
    	// delete childs[subsets[i].parent] i
    	// update count
        subsets[i].parent = find(subsets[i].parent);
    	// insert childs[subsets[i].parent] i
	}
    return subsets[i].parent;
}

void Union(long x, long y){
    long xroot = find(x);
    long yroot = find(y);
    long long updt = 0;
    
    if(subsets[xroot].rank < subsets[yroot].rank){
			//update childs
        subsets[xroot].parent = yroot;
        updt -= (_count[yroot] * (_count[yroot] + 1) / 2) + (_count[xroot] * (_count[xroot] + 1) / 2);
        _count[yroot] += _count[xroot];
        updt += _count[yroot] * (_count[yroot] + 1) / 2;
        pColor[edges[yroot][2]] += updt;
        updateBIT(edges[yroot][2], updt);
    }
    else if (subsets[xroot].rank > subsets[yroot].rank){
			//update childs
        subsets[yroot].parent = xroot;
        updt -= (_count[yroot] * (_count[yroot] + 1) / 2) + (_count[xroot] * (_count[xroot] + 1) / 2);
        _count[xroot] += _count[yroot];
        updt += _count[xroot] * (_count[xroot] + 1) / 2;
        pColor[edges[yroot][2]] += updt;
        updateBIT(edges[xroot][2], updt);
    }
    else{
			//update childs
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
        updt -= (_count[yroot] * (_count[yroot] + 1) / 2) + (_count[xroot] * (_count[xroot] + 1) / 2);
        _count[xroot] += _count[yroot];
        updt += _count[xroot] * (_count[xroot] + 1) / 2;
        pColor[edges[yroot][2]] += updt;
        updateBIT(edges[xroot][2], updt);
    }
}

void dfsutil(long e, bool visited[]){
    visited[e] = true;
    vector<long>::iterator i;
    long v = edges[e][0];
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i] && edges[e][2] == edges[*i][2]){
        	Union(e, *i);
            dfsutil(*i, visited);
        }
    }
    v = edges[e][1];
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i] && edges[e][2] == edges[*i][2]){
        	Union(e, *i);
            dfsutil(*i, visited);
        }
    }
}

void dfs(){
    bool *visited = new bool[n - 1];
    for(long i = 0; i < n - 1; i++)
        visited[i] = false;
    for(long i = 0; i < n - 1; i++)
    	if(!visited[i])
			dfsutil(i, visited);
}

void change(long i, long c){
	struct subset subsets[MAX];
long long pColor[C];
long long BITree[C];

	long iroot = find(c);
	
	//update childs
	subsets[c].parent = 
	
	long nroot = -1;
	long total = 0;
	for(vector<long>::iterator it = childs.begin(); it != childs.end(); it++){
		if(nroot == -1){
			nroot = *it;
			//update childs
			subsets[nroot].parent = nroot;
			total += count[*it];
		}
		else{
			if(edges[*it][0] != edges[iroot][0] && edges[*it][0] != edges[iroot][1] && edges[*it][1] != edges[iroot][0] && edges[*it][1] != edges[iroot][1]){
				//update childs
				subsets[*it].parent = nroot;
				total += count[*it];
			}
		}
	}
	count[nroot] += total;
	count[iroot] -= total;
	edges[i][2] = c;
}

int main(){
	long q, a, b, c, l, r, i;
	int t;
	scanf("%ld", &n);
	for(long i = 0; i < n - 1; i++){
		scanf("%ld %ld %ld", &a, &b, &c);
		a--;b--;c--;
		edges[i][0] = a;
		edges[i][1] = b;
		edges[i][2] = c;
		adj[a].push_back(i);
		adj[b].push_back(i);
		subsets[i].parent = i;
		subsets[i].rank = 0;
		_count[i] = 1;
		pColor[c]++;
		updateBIT(c, 1);
	}
	dfs();
	scanf("%ld", &q);
	for(long qq = 0; qq < q; qq++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%ld %ld", &i, &c);
			i--;c--;
			change(i, c)
		}
		else if(t == 2){
			scanf("%ld %ld", &l, &r);
			l--;r--;
			cout << (getSum(r) - getSum(l) + pColor[l]) << "\n";
		}
		else{
			scanf("%ld", i);
			i--;
			c = _count[find(i)];
			cout << (c * (c + 1) / 2) << "\n";
		}
	}
	return 0;
}
