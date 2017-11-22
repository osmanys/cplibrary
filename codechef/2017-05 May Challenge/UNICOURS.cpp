#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n, max, p;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		max = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &p);
			if(max < p)
				max = p;
		}
		printf("%d\n", n - max);
	}
	
    return 0;
}
