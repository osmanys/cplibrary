#include <bits/stdc++.h>
#define MAX 200001

using namespace std;

struct voucher{
	long l;
	long r;
	long c;
	long m;
};

vector<voucher> d[MAX];
vector<voucher> ls[MAX];
vector<voucher> rs[MAX];

bool lcomparer(voucher a, voucher b){ return a.l < b.l; }

bool rcomparer(voucher a, voucher b){ return a.r > b.r; }

bool licomparer(voucher a, voucher b){ return a.l < b.r; }

bool ricomparer(voucher a, voucher b){ return a.r > b.l; }

int main(){
	long n, x, l, r, c, cn, _min;
	scanf("%ld %ld", &n, &x);
	vector<voucher>::iterator lb;
	for(long i = 0; i < n; i++){
		scanf("%ld %ld %ld", &l, &r, &c);
		voucher v;
		v.l = l;
		v.r = r;
		v.c = c;
		d[r - l + 1].push_back(v);
		vector<voucher>::iterator it = lower_bound(ls[r - l + 1].begin(), ls[r - l + 1].end(), v, lcomparer);
		ls[r - l + 1].insert(it, v);
		it = upper_bound(rs[r - l + 1].begin(), rs[r - l + 1].end(), v, rcomparer);
		rs[r - l + 1].insert(it, v);
	}
	for(long i = 0; i < MAX; i++){
		if(d[i].size() > 0){
			_min = LONG_MAX;
			for(vector<voucher>::iterator it = ls[i].begin(); it != ls[i].end(); it++){
				if(_min > (*it).c)
					_min = (*it).c;
				(*it).m = _min;
			}
			_min = LONG_MAX;
			for(vector<voucher>::iterator it = rs[i].begin(); it != rs[i].end(); it++){
				if(_min > (*it).c)
					_min = (*it).c;
				(*it).m = _min;
			}
		}
	}
	_min = LONG_MAX;
	for(long i = 0; i <= x / 2; i++){
		for(vector<voucher>::iterator it = d[i].begin(); it != d[i].end(); it++){
			if(ls[x - i].size() > 0){
				lb = lower_bound(ls[x - i].begin(), ls[x - i].end(), (*it), licomparer);
				while(lb != ls[x - i].begin() && (*lb).l >= (*it).l)
					lb--;
				if(lb != ls[x - i].begin()){
					if(_min > (*it).c + (*lb).m)
						_min = (*it).c + (*lb).m;
				}
				lb = upper_bound(rs[x - i].begin(), rs[x - i].end(), (*it), ricomparer);
				if(_min > (*it).c + (*lb).m)
					_min = (*it).c + (*lb).m;
			}
		}
	}
	printf("%ld", _min == LONG_MAX ? -1 : _min);
	return 0;
}
