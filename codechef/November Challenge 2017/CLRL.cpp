#include <bits/stdc++.h>
 
using namespace std;
long d[1000000];
 
int main() {
	int t;
	long n, r, a, b;
	cin >> t;
	while(t--){
		scanf("%ld %ld", &n, &r);
		a = 1;b = 1e9;
		for(long i = 0; i < n; i++)
			scanf("%ld", &d[i]);
		long i = 0;
		for(; i < n; i++){
			if(a <= d[i] && b >= d[i]){
				if(d[i] > r)
					b = d[i];
				else
					a = d[i];
			}
			else{
				cout << "NO\n";
				break;
			}
		}
		if(i == n)
			cout << "YES\n";
	}
    return 0;
}
