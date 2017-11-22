#include <bits/stdc++.h>
#define MAX 151
#define MOD 1000000007
 
using namespace std;
int d[MAX];

long solve(int n){
	int a, b, i;
	long cur[MAX][MAX], bef[MAX][MAX];
	vector<pair<int, int> > pcur, pbef;
	long r = 0;
	int level = 2;
	pcur.push_back(make_pair(d[0], d[1]));
	cur[d[0]][d[1]] = 1;
	while(!pcur.empty()){
		pbef.clear();
		memset(bef, 0, sizeof bef);
		for(vector<pair<int, int> >::iterator it = pcur.begin(); it != pcur.end(); it++){
			a = (*it).first;
			b = (*it).second;
			if(level >= n && (!a || !b))
				r = (1LL * r + cur[a][b]) % MOD;
			else{
				i = 0;
				while(a - i >= 0 && b - i >= 0){
					if(!bef[b - i][d[level] + i])
						pbef.push_back(make_pair(b - i, d[level] + i));
					bef[b - i][d[level] + i] = (1LL * bef[b - i][d[level] + i] + cur[a][b]) % MOD;
					i++;
				}
			}
		}
		level++;
		pcur.swap(pbef);
		memcpy(&cur, &bef, sizeof cur);
	}
	return r;
}
 
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(d, 0, sizeof d);
		for(int i = 0; i < n; i++)
			scanf("%d", &d[i]);
		printf("%ld\n", solve(n));
	}
    return 0;
}
