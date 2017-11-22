#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int main() {
	int t, n, d;
	int data[MAX];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < 2 * n; i++){
			scanf("%d", &d);
			data[i] = d;
		}
		sort(data, data + 2 * n);
		printf("%d\n", data[3 * n / 2]);
		for(int i = 0; i < n; i++){
			printf("%d %d ", data[2 * n - 1 - i], data[i]);
		}
		printf("\n");
	}
	
    return 0;
}
