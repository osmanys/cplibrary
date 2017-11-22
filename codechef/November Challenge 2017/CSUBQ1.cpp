#include <bits/stdc++.h>
#define MAX 500000
 
using namespace std;
bool hd[MAX];
long hrang[MAX];
long *hst;
long *hstpos;
bool d[MAX];
long rang[MAX];
long *st;
long *stpos;

long getMid(long s, long e) {  return s + (e - s) / 2;  }

long updateST(long st[], long stpos[], long ss, long se, long index, long val, long si){
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

long RMQ(long st[], long stpos[], long qs, long qe, long ss, long se, long index, long &rindex){
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

void constructSTUtil(long st[], long stpos[], long ss, long se, long si){
    if (ss == se){
        st[si] = 0;
        stpos[si] = ss;
    }
    else{
	    long mid = getMid(ss, se);
	    constructSTUtil(st, stpos, ss, mid, si * 2 + 1);
	    constructSTUtil(st, stpos, mid + 1, se, si * 2 + 2);	    
		st[si] = 0;
		stpos[si] = stpos[si * 2 + 2];
	}
}

pair<long*, long*> constructST(long n){
    long x = (int)(ceil(log2(n))); 
    long max_size = 2 * (long)pow(2, x) - 1; 
    long *st = new long[max_size]; 
    long *stpos = new long[max_size]; 
    constructSTUtil(st, stpos, 0, n - 1, 0);
    return make_pair(st, stpos);
}

long long *hBITree;
long long *BITree;

long long getSum(long long BITree[], long index){
    long long sum = 0;
    index++;
    while (index){
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(long long BITree[], long n, long index, long long val){
    index++;
    while (index <= n){
       BITree[index] += val;
       index += index & (-index);
    }
}

long long* constructBITree(long n){
    long long *BITree = new long long[n + 1];
    for (long i = 1; i <= n; i++)
        BITree[i] = 0;
    return BITree;
}
 
int main() {
	int t;
	long n, q, l, r, x, y, rindex, hval, val;
	long long hresult, result;
	vector<long>::iterator it;
	cin >> n >> q >> l >> r;
	pair<long*, long*> hpst = constructST(n + 1);
	hst = hpst.first;
	hstpos = hpst.second;
	updateST(hst, hstpos, 0, n, 1, 1, 0);
	pair<long*, long*> pst = constructST(n + 1);
	st = pst.first;
	stpos = pst.second;
	updateST(st, stpos, 0, n, 1, 1, 0);
	hrang[0] = n - 1;
	rang[0] = n - 1;
	hBITree = constructBITree(n);
	updateBIT(hBITree, n, 0, 1LL * n * (n + 1) / 2);
	BITree = constructBITree(n);
	updateBIT(BITree, n, 0, 1LL * n * (n + 1) / 2);
	for(long i = 0; i < q; i++){
		scanf("%d %ld %ld", &t, &x, &y);
		if(t == 1){
			if(y <= r && hd[x - 1]){
				hd[x - 1] = false;
				if(x > 1 && !hd[x - 2] && x < n && !hd[x]){
					RMQ(hst, hstpos, 0, x, 0, n, 0, rindex);
					updateBIT(hBITree, n, x, -1LL * (hrang[x] - x + 1) * (hrang[x] - x + 2) / 2);
					updateBIT(hBITree, n, rindex - 1, 1LL * (hrang[x] - rindex + 2) * (hrang[x] - rindex + 3) / 2 - 1LL * (x - rindex) * (x - rindex + 1) / 2);
					hrang[rindex - 1] = hrang[x];
					hrang[x] = 0;
					updateST(hst, hstpos, 0, n, x + 1, 0, 0);
				}
				else if(x > 1 && !hd[x - 2]){
					RMQ(hst, hstpos, 0, x, 0, n, 0, rindex);
					updateBIT(hBITree, n, rindex - 1, 1LL * (hrang[rindex - 1] - rindex + 3));
					hrang[rindex - 1]++;
				}
				else if(x < n && !hd[x]){
					updateBIT(hBITree, n, x, -1LL * (hrang[x] - x + 1) * (hrang[x] - x + 2) / 2);
					updateBIT(hBITree, n, x - 1, 1LL * (hrang[x] - x + 2) * (hrang[x] - x + 3) / 2);
					hrang[x - 1] = hrang[x];
					hrang[x] = 0;
					updateST(hst, hstpos, 0, n, x + 1, 0, 0);
					updateST(hst, hstpos, 0, n, x, x, 0);
				}
				else{
					updateBIT(hBITree, n, x - 1, 1LL);
					hrang[x - 1] = x - 1;
					updateST(hst, hstpos, 0, n, x, x, 0);
				}
			}
			else if(y > r && !hd[x - 1]){
				hd[x - 1] = true;
				if(x > 1 && !hd[x - 2] && x < n && !hd[x]){
					RMQ(hst, hstpos, 0, x, 0, n, 0, rindex);
					updateBIT(hBITree, n, rindex - 1, 1LL * (x - rindex) * (x - rindex + 1) / 2 - 1LL * (hrang[rindex - 1] - rindex + 2) * (hrang[rindex - 1] - rindex + 3) / 2);
					updateBIT(hBITree, n, x, 1LL * (hrang[rindex - 1] - x + 1) * (hrang[rindex - 1] - x + 2) / 2);
					hrang[x] = hrang[rindex - 1];
					hrang[rindex - 1] = x - 2;
					updateST(hst, hstpos, 0, n, x + 1, x + 1, 0);
				}
				else if(x > 1 && !hd[x - 2]){
					RMQ(hst, hstpos, 0, x, 0, n, 0, rindex);
					updateBIT(hBITree, n, rindex - 1, -1LL * (hrang[rindex - 1] - rindex + 2));
					hrang[rindex - 1]--;
				}
				else if(x < n && !hd[x]){
					updateBIT(hBITree, n, x - 1, -1LL * (hrang[x - 1] - x + 2) * (hrang[x - 1] - x + 3) / 2);
					updateBIT(hBITree, n, x, 1LL * (hrang[x - 1] - x + 1) * (hrang[x - 1] - x + 2) / 2);
					hrang[x] = hrang[x - 1];
					hrang[x - 1] = 0;
					updateST(hst, hstpos, 0, n, x, 0, 0);
					updateST(hst, hstpos, 0, n, x + 1, x + 1, 0);					
				}
				else{
					updateBIT(hBITree, n, x - 1, -1LL);
					hrang[x - 1] = 0;
					updateST(hst, hstpos, 0, n, x, 0, 0);
				}
			}
			if(y < l && d[x - 1]){
				d[x - 1] = false;
				if(x > 1 && !d[x - 2] && x < n && !d[x]){
					RMQ(st, stpos, 0, x, 0, n, 0, rindex);
					updateBIT(BITree, n, x, -1LL * (rang[x] - x + 1) * (rang[x] - x + 2) / 2);
					updateBIT(BITree, n, rindex - 1, 1LL * (rang[x] - rindex + 2) * (rang[x] - rindex + 3) / 2 - 1LL * (x - rindex) * (x - rindex + 1) / 2);
					rang[rindex - 1] = rang[x];
					rang[x] = 0;
					updateST(st, stpos, 0, n, x + 1, 0, 0);
				}
				else if(x > 1 && !d[x - 2]){
					RMQ(st, stpos, 0, x, 0, n, 0, rindex);
					updateBIT(BITree, n, rindex - 1, 1LL * (rang[rindex - 1] - rindex + 3));
					rang[rindex - 1]++;
				}
				else if(x < n && !d[x]){
					updateBIT(BITree, n, x, -1LL * (rang[x] - x + 1) * (rang[x] - x + 2) / 2);
					updateBIT(BITree, n, x - 1, 1LL * (rang[x] - x + 2) * (rang[x] - x + 3) / 2);
					rang[x - 1] = rang[x];
					rang[x] = 0;
					updateST(st, stpos, 0, n, x + 1, 0, 0);
					updateST(st, stpos, 0, n, x, x, 0);
				}
				else{
					updateBIT(BITree, n, x - 1, 1LL);
					rang[x - 1] = x - 1;
					updateST(st, stpos, 0, n, x, x, 0);
				}
			}
			else if(y >= l && !d[x - 1]){
				d[x - 1] = true;
				if(x > 1 && !d[x - 2] && x < n && !d[x]){
					RMQ(st, stpos, 0, x, 0, n, 0, rindex);
					updateBIT(BITree, n, rindex - 1, 1LL * (x - rindex) * (x - rindex + 1) / 2 - 1LL * (rang[rindex - 1] - rindex + 2) * (rang[rindex - 1] - rindex + 3) / 2);
					updateBIT(BITree, n, x, 1LL * (rang[rindex - 1] - x + 1) * (rang[rindex - 1] - x + 2) / 2);
					rang[x] = rang[rindex - 1];
					rang[rindex - 1] = x - 2;
					updateST(st, stpos, 0, n, x + 1, x + 1, 0);
				}
				else if(x > 1 && !d[x - 2]){
					RMQ(st, stpos, 0, x, 0, n, 0, rindex);
					updateBIT(BITree, n, rindex - 1, -1LL * (rang[rindex - 1] - rindex + 2));
					rang[rindex - 1]--;
				}
				else if(x < n && !d[x]){
					updateBIT(BITree, n, x - 1, -1LL * (rang[x - 1] - x + 2) * (rang[x - 1] - x + 3) / 2);
					updateBIT(BITree, n, x, 1LL * (rang[x - 1] - x + 1) * (rang[x - 1] - x + 2) / 2);
					rang[x] = rang[x - 1];
					rang[x - 1] = 0;
					updateST(st, stpos, 0, n, x, 0, 0);
					updateST(st, stpos, 0, n, x + 1, x + 1, 0);					
				}
				else{
					updateBIT(BITree, n, x - 1, -1LL);
					rang[x - 1] = 0;
					updateST(st, stpos, 0, n, x, 0, 0);
				}
			}
		}
		else{
			hresult = getSum(hBITree, y - 1) - getSum(hBITree, x - 2);
			hval = RMQ(hst, hstpos, 0, x - 1, 0, n, 0, rindex);
			if(hval && hrang[rindex - 1] >= x - 1){
				hresult += 1LL * (min(y - 1, hrang[rindex - 1]) - x + 2) * (min(y - 1, hrang[rindex - 1]) - x + 3) / 2;
			}
			hval = RMQ(hst, hstpos, x, y, 0, n, 0, rindex);
			if(hval && hrang[rindex - 1] > y - 1){
				hresult -= 1LL * (hrang[rindex - 1] - rindex + 2) * (hrang[rindex - 1] - rindex + 3) / 2;
				hresult += 1LL * (y - rindex + 1) * (y - rindex + 2) / 2;
			}
			
			result = getSum(BITree, y - 1) - getSum(BITree, x - 2);
			val = RMQ(st, stpos, 0, x - 1, 0, n, 0, rindex);
			if(val && rang[rindex - 1] >= x - 1){
				result += 1LL * (min(y - 1, rang[rindex - 1]) - x + 2) * (min(y - 1, rang[rindex - 1]) - x + 3) / 2;
			}
			val = RMQ(st, stpos, x, y, 0, n, 0, rindex);
			if(val && rang[rindex - 1] > y - 1){
				result -= 1LL * (rang[rindex - 1] - rindex + 2) * (rang[rindex - 1] - rindex + 3) / 2;
				result += 1LL * (y - rindex + 1) * (y - rindex + 2) / 2;
			}
			cout << (hresult - result) << "\n";
		}
	}
    return 0;
}
