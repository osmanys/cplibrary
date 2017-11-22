#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
long d[MAX];
long dist[MAX];

int main(){
	int t;
	long n, l, a, b, m;
	long long r;
	cin >> t;
	while(t--){
		cin >> n >> l >> a >> b;
		for(long i = 0; i < n; i++)
			cin >> d[i];
		sort(d, d + n);
		if(n & 1)
			m = d[n / 2];
		else
			m = (d[n / 2 - 1] + d[n / 2]) / 2;
		for(long i = 0; i < n; i++)
			dist[i] = m - (l * (n / 2 - i)) - d[i];
		if(m - (l * (n / 2)) < a){
			for(long i = 0; i < n; i++)
				dist[i] += a - m + (l * (n / 2));
		}
		else if(m - (l * (n / 2 - n)) > b){
			for(long i = 0; i < n; i++)
				dist[i] -= m - (l * (n / 2 - n)) - b;			
		}
		r = 0;		
		for(long i = 0; i < n; i++)
			r += abs(dist[i]);
		cout << r << endl;
	}
	
	return 0;
}
