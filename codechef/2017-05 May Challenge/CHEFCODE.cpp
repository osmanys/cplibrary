#include <bits/stdc++.h>
#define PROD(a, b) ((1.0f * LLONG_MAX / a < b) ? LLONG_MAX : a * b)

using namespace std;

long long total_nodes;

void subset_prod(long long s[], int size, long long prod, int ite, long long target_prod){
	total_nodes++;
    for(int i = ite; i < size && PROD(prod, s[i]) <= target_prod; i++)
        subset_prod(s, size, PROD(prod, s[i]), i + 1, target_prod);
}

void generateSubsets(long long s[], int size, long long target_prod){
    long long total = 1;
    sort(s, s + size);
    for(int i = 0; i < size; i++)
        total = PROD(total, s[i]);
    if(total <= target_prod)
    	total_nodes = (1LL << size) - 1;
    else{
        subset_prod(s, size, 1, 0, target_prod);
        total_nodes--;
    }
}
 
int main() {
	int n, c;
	long long k, v;
	scanf("%d %lld", &n, &k);
	long long data[n];
	c = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", &v);
		if(v <= k){
			data[c] = v;
			c++;
		}
	}
	generateSubsets(data, c, k);
	printf("%lld", total_nodes);
	
    return 0;
}
