#include <bits/stdc++.h>
#define MAX 3000000

using namespace std;
vector<pair<long, pair<long, long> > > strs;
vector<string> strlist;
char res[MAX];

int main(){
	long n, k, sz, x, _max = -1, i;
	string s;
	scanf("%ld", &n);
	for(long i = 0; i < n; i++){
		cin >> s >> k;
		strlist.push_back(s);
		sz = s.size();
		for(long j = 0; j < k; j++){
			scanf("%ld", &x);
			strs.push_back(make_pair(x, make_pair(sz, i)));
		}
	}
	sort(strs.begin(), strs.end());
	for(vector<pair<long, pair<long, long> > >::iterator it = strs.begin(); it != strs.end(); it++){
		if((*it).first + (*it).second.first - 1 > _max){
			i = max(_max, (*it).first - 1);
			for(; i < (*it).first + (*it).second.first - 1; i++)
				res[i] = strlist[(*it).second.second][i - (*it).first + 1];
			_max = i;
		}
	}
	for(long i = 0; i < _max; i++){
		if(res[i])
			cout << res[i];
		else
			cout << 'a';
	}		
	return 0;
}
