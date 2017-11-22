#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

list<pair<int, int> > li[MAX];
long long dp[MAX][30];
int lev[MAX];
int dist[MAX];

int dfs(int start, int par, int le){
	lev[start] = le;
	list<pair<int, int> >::iterator it;
	for(it = li[start].begin(); it != li[start].end(); it++){
		if(it->first != par){
			dp[it->first][0] = start;
			lev[it->first] = le + 1;
			dfs(it->first, start, le + 1);
		}
	}	
	return 0;
}

int binaryRoot(int a, int k){
	int lg;
	for(lg = 1; (1 << lg) <= lev[a]; lg++);
		lg--;
	for(int i = lg; i >= 0; i--){
		if(k >= (1 << i) && dp[a][i] != -1){
			k -= (1 << i);
			a = dp[a][i];
		}
		if(!k)
			return a;
	}
	return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < MAX; i++)
			li[i].clear();
		int n;
		cin >> n;
		int sp;
		int mxid = 0;
		for(int i = 1;i <= n; i++){
			int a, b, c;
			cin >> a >> b;
			mxid = max(mxid, a);
			mxid = max(mxid, b);			
			if(!b)
				sp = a;
			else{
				li[a].push_back(make_pair(b, c));
				li[b].push_back(make_pair(a, c));
			}		
		}
		
		memset(dp, -1, sizeof dp);		
		dp[sp][0] = 0;		
		dfs(sp, -1, 1);		
		int max_h = 25;
		for(int i = 1; i <= max_h; i++){
			for(int j = 1; j <= mxid; j++){
				if(dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
			}
		}
		
		int q;
		cin >> q;
		while(q--){
			int type;
			cin >> type;
			if(type == 1){
				int x;
				cin >> x;
				for(int i = 0; i < 25; i++){
					dp[x][i] = -1;
					lev[x] = 0;
				}
			}
			else if(!type){
				int a,b;
				cin >> a >> b;
				dp[b][0] = a;
				lev[b] = lev[a] + 1;
				for(int i = 1; i < 25; i++){
					if(dp[b][i - 1] != -1)
						dp[b][i] = dp[dp[b][i - 1]][i - 1];
				}
			}
			else{
				int a, k;
				cin >> a >> k;
				int ans = binaryRoot(a, k);
				if(ans == -1)
					cout << 0 << endl;
				else
					cout << ans << endl;
			}
		}
	}
	return 0;
}
