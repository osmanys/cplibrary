#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 100002
 
using namespace std;
vector<pair<int, pair<long, long> > > cm;
long incQBT[MAX], decQBT[MAX], incVBT[MAX], decVBT[MAX];

long getsum(long bitree[], long index){
    long sum = 0;
    index++;
    while (index > 0){
        sum = (sum + bitree[index]) % MOD;
        index -= index & (-index);
    }
    return sum;
}

void updatebit(long bitree[], long n, long index, long val){
    index++;
    while (index <= n){
       bitree[index] = (bitree[index] + val) % MOD;
       index += index & (-index);
    }
}

int main() {
	int t, tp;
	long n, m, l, r, v;
	scanf("%d", &t);
	while(t--){
		scanf("%ld %ld", &n, &m);
		cm.clear();
		memset(incQBT, 0, sizeof incQBT);
		memset(decQBT, 0, sizeof decQBT);
		memset(incVBT, 0, sizeof incVBT);
		memset(decVBT, 0, sizeof decVBT);
		for(long i = 0; i < m; i++){
			scanf("%d %ld %ld", &tp, &l, &r);
			cm.push_back(make_pair(tp, make_pair(l - 1, r - 1)));
		}
		for(long i = cm.size() - 1; i >= 0; i--){
			v = (MOD + getsum(incQBT, i) - getsum(decQBT, i)) % MOD;
			if(cm[i].first == 1){
				updatebit(incVBT, n, cm[i].second.first, v + 1);
				updatebit(decVBT, n, cm[i].second.second + 1, v + 1);
			}
			else{
				updatebit(incQBT, m, cm[i].second.first, v + 1);
				updatebit(decQBT, m, cm[i].second.second + 1, v + 1);
			}
		}
		for(long i = 0; i < n; i++){
			printf("%ld ", (MOD + getsum(incVBT, i) - getsum(decVBT, i)) % MOD);
		}
		printf("\n");
	}
    return 0;
}
