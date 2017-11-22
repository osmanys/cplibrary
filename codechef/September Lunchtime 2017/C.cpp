#include <bits/stdc++.h>
 
using namespace std;
vector<pair<long, long> > d;
 
int main() {
	int t;
	long n, k, p, q, j;
	long long r;
	cin >> t;
	while(t--){
		cin >> n >> k;
		d.clear();
		for(long i = 0; i < k; i++){
			scanf("%ld %ld", &p, &q);
			d.push_back(make_pair(p, q));
		}
		sort(d.begin(), d.end());
		r = 0;		
		for(long i = 0; i <= k; i++){
			p = (i < k ? d[i].first : n + 1) - (i > 0 ? d[i - 1].first : 0) - 1;
			if(p & 1)
				r += (1LL * p + 1) * (p + 1) / 4;
			else
				r += 1LL * p * (p + 2) / 4;
		}
		for(long i = 0; i < k; i++){
			for(j = 0; i - j >= 0 && i + j < k; j++){
				if(d[i].first - d[i - j].first != d[i + j].first - d[i].first || d[i - j].second != d[i + j].second)
					break;
			}
			r++;
			if(i - j < 0 && i + j >= k)
				r += min(d[i].first - 1, n - d[i].first);
			else if(i - j < 0)
				r += min(d[i].first - 1, d[i + j].first - d[i].first - 1);
			else if(i + j >= k)
				r += min(d[i].first - d[i - j].first - 1, n - d[i].first);
			else
				r += min(d[i].first - d[i - j].first - 1, d[i + j].first - d[i].first - 1);
		}
		for(long i = 1; i < k; i++){
			if(((d[i].first - d[i - 1].first) & 1) || (d[i].second != d[i - 1].second))
				continue;
			for(j = 0; i - 1 - j >= 0 && i + j < k; j++){
				if(d[i - 1].first - d[i - 1 - j].first != d[i + j].first - d[i].first || d[i - 1 - j].second != d[i + j].second)
					break;
			}
			r++;
			if(i - 1 - j < 0 && i + j >= k)
				r += min(d[i - 1].first - 1, n - d[i].first);
			else if(i - 1 - j < 0)
				r += min(d[i - 1].first - 1, d[i + j].first - d[i].first - 1);
			else if(i + j >= k)
				r += min(d[i - 1].first - d[i - 1 - j].first - 1, n - d[i].first);
			else
				r += min(d[i - 1].first - d[i - 1 - j].first - 1, d[i + j].first - d[i].first - 1);
		}
		cout << r << "\n";
	}
    return 0;
}
