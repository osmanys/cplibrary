#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, count, _min = 1001;
	string s, t;
	vector<int> _index, index_min;
	scanf("%d %d", &n, &m);
	cin >> s;
	cin >> t;
	for(int i = 0; i <= m - n; i++){
		count = 0;
		_index.clear();
		for(int j = 0; j < n; j++){
			if(s[j] != t[i + j]){
				count++;
				_index.push_back(j + 1);
			}
		}
		if(_min > count){
			_min = count;
			index_min = _index;
		}
	}
	printf("%d\n", _min);
	for(int i = 0; i < _min; i++){
		printf("%d ", index_min[i]);
	}
	return 0;
}
