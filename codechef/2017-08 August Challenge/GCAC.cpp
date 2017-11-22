#include <bits/stdc++.h>
#define MAX 1000
 
using namespace std;
long minSalary[MAX], offeredSalary[MAX], maxOffers[MAX];
bool qual[MAX][MAX];
int hire[MAX];
 
int main() {
	int t, n, m, jobs, sel, nHire;
	long maxO;
	long long salary;
	char c;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%ld", &minSalary[i]);
		for(int i = 0; i < m; i++)
			scanf("%ld %ld", &offeredSalary[i], &maxOffers[i]);
		for(int i = 0; i < n; i++){
			scanf("%c", &c);
			for(int j = 0; j < m; j++){
				scanf("%c", &c);
				qual[i][j] = (c == '1');
			}
		}
		memset(hire, 0, sizeof(int) * m);
		jobs = 0; salary = 0;
		for(int i = 0; i < n; i++){
			maxO = 0;
			sel = -1;
			for(int j = 0; j < m; j++){
				if(qual[i][j]){
					if(maxOffers[j] > hire[j] && minSalary[i] <= offeredSalary[j] && offeredSalary[j] > maxO){
						maxO = offeredSalary[j];
						sel = j;
					}
				}
			}
			if(sel != -1){
				jobs++;
				salary += maxO;
				hire[sel]++;
			}
		}
		nHire = 0;
		for(int j = 0; j < m; j++){
			if(!hire[j])
				nHire++;
		}
		cout << jobs << " " << salary << " " << nHire << "\n";
	}	
    return 0;
}
