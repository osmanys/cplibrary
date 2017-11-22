#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > d;

int main(){
	int n, a;
	long long k, r, p;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		d.push_back(make_pair(a, i + 1));
	}
	sort(d.begin(), d.end());
	cin >> k;
	r = 0;
	for(int i = 0; i < n && k > 0; i++){
		p = min(k / d[i].first, 1LL * d[i].second);
		k -= p * d[i].first;
		r += p;
	}
	cout << r;
	return 0;
}
