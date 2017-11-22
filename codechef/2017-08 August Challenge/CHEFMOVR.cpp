#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;
long a[MAX];
long long med[MAX];
list<int> pos[MAX], neg[MAX];
 
int main() {
	int t, n, d, i, k, j, p;
	long m;
	long long r;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &d);
		for(i = 0; i < d; i++){
			med[i] = 0;
			pos[i].clear();
			neg[i].clear();
		}
		for(i = 0; i < n; i++){
			scanf("%ld", &a[i]);
			med[i % d] += a[i];
		}
		m = 0;
		for(i = 0; i < d; i++){
			if(med[i] % (n / d + (n % d > i)))
				break;
			med[i] /= (n / d + (n % d > i));
			if(m){
				if(m != med[i])
					break;
			}
			else
				m = med[i];
		}
		if(i < d){
			printf("-1\n");
			continue;
		}
		for(i = 0; i < n; i++){
			a[i] -= m;
			if(a[i] < 0)
				neg[i % d].push_back(i);
			else if(a[i] > 0){
				pos[i % d].push_back(i);
			}				
		}
		r = 0;
		for(i = 0; i < d; i++){
			for(p = 0; p * d + i < n; p++){
				j = p * d + i;
				if(a[j] > 0){
					while(a[j] != 0){
						k = neg[i].front();
						r += a[j] * (k - j) / d;
						if(a[j] + a[k] >= 0){
							a[j] += a[k];
							a[k] = 0;
							neg[i].pop_front();
						}
						else{
							a[k] += a[j];
							a[j] = 0;
						}
						r -= a[j] * (k - j) / d;
					}
				}
				else if(a[j] < 0){
					while(a[j] != 0){
						k = pos[i].front();
						r -= a[j] * (k - j) / d;
						if(a[j] + a[k] <= 0){
							a[j] += a[k];
							a[k] = 0;
							pos[i].pop_front();
						}
						else{
							a[k] += a[j];
							a[j] = 0;
						}
						r += a[j] * (k - j) / d;
					}					
				}
			}
		}
		cout << r << "\n";
	}
	
    return 0;
}
