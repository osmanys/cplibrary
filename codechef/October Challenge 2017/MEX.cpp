#include <bits/stdc++.h>
#define MAX 200001
 
using namespace std;
bool d[MAX];
 
int main() {
	int t;
	cin >> t;
	long s, n, k;
	while(t--){
		scanf("%ld %ld", &n, &k);
		memset(d, false, sizeof d);
		for(long i = 0; i < n; i++){
			scanf("%ld", &s);
			d[s] = true;
		}
		for(long i = 0; i < MAX; i++){
			if(!d[i]){
				if(!k){
					printf("%ld\n", i);
					break;
				}
				k--;
			}
		}
	}
    return 0;
}
