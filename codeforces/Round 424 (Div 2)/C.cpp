#include <bits/stdc++.h>
#define MAX 2000

using namespace std;
long a[MAX];
set<long long> b;
set<long long> res;
set<long long> pres;
long long p[MAX];

int main(){
	int k, n, t;
	long llt;
	scanf("%d %d", &k, &n);
	scanf("%d", &t);
	a[0] = t;
	for(int i = 1; i < k; i++){
		scanf("%d", &t);
		a[i] = t + a[i - 1];
	}
	for(int i = 0; i < n; i++){
		cin >> llt;
		b.insert(llt);
	}
	for(int i = 0; i < k; i++){
		p[i] = llt - a[i];
	}
	int j, pr, r = 0;
	for(int i = 0; i < k; i++){
		pr = 0;
		pres.clear();
		j = 0;
		for(; j < k; j++){
			if(b.find(p[i] + a[j]) != b.end() && pres.find(p[i] + a[j]) == pres.end()){
				pr++;
				pres.insert(p[i] + a[j]);
			}
		}
		if(pr == n && res.find(p[i]) == res.end()){
			r++;
			res.insert(p[i]);
		}
	}
	printf("%d", r);
	return 0;
}
