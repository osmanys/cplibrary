#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	long d[n], _min, _max, _mint;
	for(int i = 0; i < n; i++)
		cin >> d[i];
	_min = ((n == 1) ? 0 : min(d[n - 1], d[n - 2]));
	_max = ((n == 1) ? d[0] : max(d[n - 1], d[n - 2]));
	for(int i = n - 3; i >= 0; i--){
		_mint = min(_max, d[i] + _min);
		_max = max(_max, d[i] + _min);
		_min = _mint;
	}
	cout << _min << " " << _max;
	return 0;
}
