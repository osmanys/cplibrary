#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k, f;
	cin >> n >> m;
	int _maxk = n;
	vector<pair<int, int> > d;
	for(int i = 0; i < m; i++){
		cin >> k >> f;
		d.push_back(make_pair(k, f));
		if(_maxk < k)
			_maxk = k;
	}
	int ri = -1;bool valid;
	for(int i = 1; i <= _maxk; i++){
		valid = true;
		for(int j = 0; j < m; j++){
			k = d[j].first;
			f = d[j].second;
			if((k <= (f - 1) * i) || (k > f * i)){
				valid = false;
				break;
			}
		}
		if(valid){
			if(ri != -1){
				if(ri != n / i + (n % i != 0)){
					ri = -1;
					break;
				}
			}
			else
				ri = n / i + (n % i != 0);
		}
	}
	cout << ri;
	return 0;
}
