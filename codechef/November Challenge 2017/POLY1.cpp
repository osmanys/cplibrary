#include <bits/stdc++.h>
#define MAX 100002
#define BUCKET (long)(MAX / log(MAX))
 
using namespace std;
long p[MAX][4];
long im[MAX];
long nextm[MAX];
long long m[MAX];
vector<long> roots[MAX];
long qs[MAX];

long *st;
long *stpos;

long getMid(long s, long e) {  return s + (e - s) / 2;  }

long updateST(long *st, long *stpos, long ss, long se, long index, long val, long si){
    if (index < ss || index > se)
        return st[si];
	if (ss == se){
        st[si] = val;
        stpos[si] = ss;
        return val;
    }
	long mid = getMid(ss, se);
	long rm1 = updateST(st, stpos, ss, mid, index, val, 2 * si + 1);
	long rm2 = updateST(st, stpos, mid + 1, se, index, val, 2 * si + 2);	
    if(rm1 > rm2){
    	st[si] = rm1;
    	stpos[si] = stpos[si * 2 + 1];
	}
	else{
    	st[si] = rm2;
    	stpos[si] = stpos[si * 2 + 2];
	}
    return st[si];
}

long RMQ(long *st, long *stpos, long qs, long qe, long ss, long se, long index, long &rindex){
	rindex = stpos[index];
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return LONG_MIN;
    long mid = getMid(ss, se);
    long rindex1, rindex2;
    long rm1 = RMQ(st, stpos, qs, qe, ss, mid, 2 * index + 1, rindex1);
    long rm2 = RMQ(st, stpos, qs, qe, mid + 1, se, 2 * index + 2, rindex2);
    if(rm1 > rm2){
    	rindex = rindex1;
    	return rm1;
	}
	else{
    	rindex = rindex2;
		return rm2;
	}
}

long constructSTUtil(long *st, long *stpos, long arr[], long ss, long se, long si){
    if (ss == se){
        st[si] = arr[ss];
        stpos[si] = ss;
        return arr[ss];
    }
    long mid = getMid(ss, se);
    long rm1 = constructSTUtil(st, stpos, arr, ss, mid, si * 2 + 1);
    long rm2 = constructSTUtil(st, stpos, arr, mid+1, se, si * 2 + 2);
    if(rm1 > rm2){
    	st[si] = rm1;
    	stpos[si] = stpos[si * 2 + 1];
	}
	else{
    	st[si] = rm2;
    	stpos[si] = stpos[si * 2 + 2];
	}
    return st[si];
}

pair<long*, long*>  constructST(long arr[], long n){
    long x = (int)(ceil(log2(n))); 
    long max_size = 2 * (long)pow(2, x) - 1; 
    long *st = new long[max_size]; 
    long *stpos = new long[max_size]; 
    constructSTUtil(st, stpos, arr, 0, n - 1, 0);
    return make_pair(st, stpos);
}

long long eval(long i, long t){
	return 1LL * p[i][0] + 1LL * p[i][1] * t + 1LL * p[i][2] * t * t + 1LL * p[i][3] * t * t * t;
}

void build(long n){
	memset(im, 0, sizeof im);
	pair<long*, long*> pst = constructST(im, MAX);
	st = pst.first;
	stpos = pst.second;
	long imin;
	for(long ind = 0; ind <= 10; ind++){
		m[ind] = LLONG_MAX;
		for(long i = 0; i < n; i++){
			if(m[ind] > eval(i, ind)){
				m[ind] = eval(i, ind);
				im[ind] = i + 1;
			}
		}
		nextm[ind] = ind + 1;
		updateST(st, stpos, 0, MAX - 1, ind, ind, 0);
	}
	long ind = BUCKET + 10;
	for(; ind + 1 < MAX; ind += BUCKET){
		m[ind] = LLONG_MAX;		
		for(long k = 0; k < n; k++){
			if(m[ind] > eval(k, ind)){
				m[ind] = eval(k, ind);
				im[ind] = k + 1;
			}
		}
		nextm[ind - BUCKET] = ind;
		updateST(st, stpos, 0, MAX - 1, ind, ind, 0);
		for(long k = 0; k < n; k++){
			if(abs(eval(im[ind] - 1, ind) - eval(k, ind)) < abs(eval(im[ind] - 1, ind + 1) - eval(k, ind + 1)))
				roots[ind].push_back(k);
		}
		roots[ind].push_back(im[ind] - 1);
	}
	if(!im[MAX - 2]){
		nextm[ind - BUCKET] = MAX - 2;
		ind = MAX - 2;
		m[ind] = LLONG_MAX;
		for(long k = 0; k < n; k++){
			if(m[ind] > eval(k, ind)){
				m[ind] = eval(k, ind);
				im[ind] = k + 1;
			}
		}
		updateST(st, stpos, 0, MAX - 1, ind, ind, 0);
		for(long k = 0; k < n; k++){
			if(abs(eval(im[ind] - 1, ind) - eval(k, ind)) < abs(eval(im[ind] - 1, ind + 1) - eval(k, ind + 1)))
				roots[ind].push_back(k);
		}
		roots[ind].push_back(im[ind] - 1);
	}
}

void calc(long qs, long qe, long t){
	if(im[qs] == im[qe]){
		im[t] = im[qs];
		m[t] = eval(im[t] - 1, t);
		return;
	}
	long ind = getMid(qs, qe);
	m[ind] = LLONG_MAX;
	for(vector<long>::iterator it = roots[qe].begin(); it != roots[qe].end(); it++){
		if(m[ind] > eval(*it, ind)){
			m[ind] = eval(*it, ind);
			im[ind] = *it + 1;
		}
	}
	nextm[ind] = qe;
	nextm[qs] = ind;
	updateST(st, stpos, 0, MAX - 1, ind, ind, 0);
	if(ind - qs > 1 && im[qs] != im[ind]){
		roots[qs].clear();
		for(vector<long>::iterator it = roots[qe].begin(); it != roots[qe].end(); it++){
			if(abs(eval(im[ind] - 1, ind) - eval(*it, ind)) >= abs(eval(im[ind] - 1, ind + 1) - eval(*it, ind + 1)))
				roots[qs].push_back(*it);
			else
				roots[ind].push_back(*it);
		}
		roots[ind].push_back(im[ind] - 1);
	}
	if(!im[t]){
		if(t < ind)
			calc(qs, ind, t);
		else
			calc(ind, qe, t);
	}
}
 
int main() {
	int T;
	long n, q, t, rindex, _im;
	long long _m;
	cin >> T;
	srand (time(NULL));
	while(T--){
		//cin >> n;
		n = 10;
		for(long i = 0; i < n; i++){
			//scanf("%ld %ld %ld %ld", &p[i][0], &p[i][1], &p[i][2], &p[i][3]);
			p[i][0] = rand() % 100001;
			p[i][1] = rand() % 100001;
			p[i][2] = rand() % 100001;
			p[i][3] = rand() % 1001;
			//cout << p[i][0] << " " << p[i][1] << " " << p[i][2] << " " << p[i][3] << "\n";
		}
		build(n);
		//cin >> q;
		q = 100001;
		for(long i = 0; i < q; i++){
			//scanf("%ld", &t);
			t = i;
			qs[i] = t;
			if(!im[t]){	
				RMQ(st, stpos, 0, t, 0, MAX - 1, 0, rindex);
				calc(rindex, nextm[rindex], t);
			}
			//cout << m[t] << "\n";
		}
		cout << "begin test\n";
		for(long i = 0; i < q; i++){
			_m = LLONG_MAX;
			for(long k = 0; k < n; k++){
				if(_m > eval(k, qs[i])){
					_m = eval(k, qs[i]);
					_im = k;
				}
			}
			//cout << (_im + 1) << "\n";
			if(m[qs[i]] != _m)
				cout << "error query#" << i << "\n";
		}
		cout << "end test\n";
	}
    return 0;
}
