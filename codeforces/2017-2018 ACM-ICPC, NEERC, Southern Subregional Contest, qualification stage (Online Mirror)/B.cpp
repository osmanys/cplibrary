#include <bits/stdc++.h>
#define MAX 200000

using namespace std;
vector<long> d[MAX];
long m[MAX];

int main(){
	long n, t, p;
	scanf("%ld", &n);
	for(long i = 0; i < n; i++){
		scanf("%ld", &t);
		p = upper_bound(m, m + n, t, std::greater<long>()) - m;
		d[p].push_back(t);
		m[p] = t;
	}
	long i = 0;
	while(!d[i].empty()){
		for(vector<long>::iterator it = d[i].begin(); it != d[i].end(); it++)
			printf("%ld ", *it);
		printf("\n");
		i++;
	}
	return 0;
}
