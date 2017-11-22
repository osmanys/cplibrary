#include <bits/stdc++.h>
#define fi "B-large-practice.in"
#define fo "B-large-practice.out"
#define MAX 2500

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n, h;
    scanf("%d", &t);
    int count[MAX];
    set<int> result;
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d:", tt);
		scanf("%d", &n);
		memset(count, 0, sizeof count);
		for(int i = 0; i < 2 * n * n - n; i++){
			scanf("%d", &h);
			count[h - 1]++;
		}
		result.clear();
		for(int i = 0; i < MAX; i++){
			if(count[i]&1)
				result.insert(i + 1);
		}
		for(set<int>::iterator it = result.begin(); it != result.end(); it++){
			printf(" %d", *it);
		}
		printf("\n");
	}
    
	return 0;
}
