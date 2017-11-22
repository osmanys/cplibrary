#include<bits/stdc++.h>
#define MAX 1000000
#define MAXSZ (1 << 21)

using namespace std;

struct node{
	long long mx;
	long cnt, pos; 
	node(){
		mx = 1 << 31;
		cnt = -1;
		pos = 0;
	}
	node(long long mx, long cnt, long pos){
		this->mx = mx;
		this->cnt = cnt;
		this->pos = pos;
	}
};

node tree[MAXSZ];
long v[MAX];
long long lazy[MAXSZ];

long long getmx(long pos, long ss, long se, long si){
	if (lazy[si]){
		tree[si].mx += lazy[si];
		if (ss != se){
			lazy[2 * si] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	long mid = (ss + se) / 2;
	if (ss == se)
		return tree[si].mx;
	if (pos <= mid)
		return getmx(pos, ss, mid, si * 2);
	else
		return getmx(pos, mid + 1, se, si * 2 + 1);
}

node find(long long mx, long ss, long se, long si){
	if (lazy[si]){
		tree[si].mx += lazy[si];
		if (ss != se){
			lazy[2 * si] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	long mid = (ss + se) / 2;
	if (ss == se){
		if (tree[si].mx >= mx)
			return tree[si];
		else
			return node();
	}
	node pr = node();
	if (tree[si * 2].mx + lazy[si * 2] < mx && tree[si * 2 + 1].mx + lazy[si * 2 + 1] < mx)
		return pr;
	if (tree[si * 2].mx + lazy[si * 2] < mx)
		pr = find(mx, mid + 1, se, si * 2 + 1);
	else{
		pr = find(mx, ss, mid, si * 2);
		if (pr.cnt != -1 && tree[si * 2 + 1].mx + lazy[si * 2 + 1] > tree[si * 2].mx + lazy[si * 2])
			pr.cnt = tree[si].cnt - (tree[si * 2].cnt - pr.cnt);
	}
	return pr;
}

void update(long qs, long qe, long ss, long se, long val, long si){
	if (lazy[si]){
		tree[si].mx += lazy[si];
		if (ss != se){
			lazy[2 * si] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (qs <= ss && se <= qe){
		tree[si].mx += val;
		if (ss != se){
			lazy[2 * si] += val;
			lazy[2 * si + 1] += val;
		}
		return;
	}
	long mid = (ss + se) / 2;
	if (qs <= mid)
		update(qs, qe, ss, mid, val, si * 2);
	if (qe > mid)
		update(qs, qe, mid + 1, se, val, si * 2 + 1);
	node pr = find(tree[si * 2].mx + lazy[2 * si] + 1, mid + 1, se, si * 2 + 1);
	if (tree[si * 2].mx + lazy[si * 2] > tree[si * 2 + 1].mx + lazy[si * 2 + 1] || pr.cnt == -1){
		tree[si].mx = tree[si * 2].mx + lazy[si * 2];
		tree[si].cnt = tree[si * 2].cnt;
		tree[si].pos = tree[si * 2].pos;
	}
	else{
		tree[si].mx = tree[si * 2 + 1].mx + lazy[si * 2 + 1];
		tree[si].cnt = tree[si * 2].cnt + pr.cnt;
		tree[si].pos = tree[si * 2 + 1].pos;
	}
}

node query(long long mx, long &cnt, long pos, long qs, long qe, long ss, long se, long si){
	if (lazy[si]){
		tree[si].mx += lazy[si];
		if (ss != se){
			lazy[2 * si] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	long mid = (ss + se) / 2;
	node e1 = node(), e2 = node();
	if (ss == se){
		if (tree[si].mx < mx || !cnt || tree[si].pos - pos > 100)
			return e1;
		else{
			--cnt;
			return tree[si];
		}
	}
	if (qs <= ss && se <= qe){
		node pr1 = find(mx, ss, mid, si * 2);
		long long cx = tree[si * 2].mx + lazy[si * 2] + 1;
		long cz = tree[si * 2].pos;
		if (pr1.cnt == -1){
			pr1.cnt = 0;
			cx = mx;
			cz = pos;
		}
		node pr2 = find(cx, mid + 1, se, si * 2 + 1);
		if (cnt <= pr1.cnt)
			return query(mx, cnt, pos, qs, qe, ss, mid, si * 2);
		else if (cnt <= pr1.cnt + pr2.cnt){
			cnt -= pr1.cnt;
			return query(cx, cnt, cz, qs, qe, mid + 1, se, si * 2 + 1);
		}
		else{
			if (pr2.cnt == -1){
				pr2.cnt = 0;
				if (!pr1.cnt)
					return e1;
				else{
					e1.mx = tree[si * 2].mx + lazy[si * 2];
					e1.cnt = pr1.cnt;
					e1.pos = tree[si * 2].pos;
				}
			}
			else{
				e1.mx = tree[si * 2 + 1].mx + lazy[si * 2 + 1];
				e1.cnt = pr1.cnt + pr2.cnt;
				e1.pos = tree[si * 2 + 1].pos;
			}
			cnt -= pr1.cnt + pr2.cnt;
			return e1;
		}
	}
	if (qs <= mid)
		e1 = query(mx, cnt, pos, qs, qe, ss, mid, si * 2);
	if (qe > mid){
		if (e1.cnt == -1)
			e2 = query(mx, cnt, pos, qs, qe, mid + 1, se, si * 2 + 1);
		else
			e2 = query(e1.mx + 1, cnt, e1.pos, qs, qe, mid + 1, se, si * 2 + 1);
	}
	if (e1.cnt != -1 && e2.cnt != -1)
		return e2;
	if (e1.cnt != -1)
		return e1;
	else if (e2.cnt != -1)
		return e2;
	else
		return e1;
}

void build(long ss, long se, long si){
	if (ss == se){
		tree[si].mx = v[ss];
		tree[si].cnt = 1;
		tree[si].pos = ss;
		return;
	}
	long mid = (ss + se) / 2;
	build(ss, mid, si * 2);
	build(mid + 1, se, si * 2 + 1);
	node pr = find(tree[si * 2].mx + 1, mid + 1, se, si * 2 + 1);
	if (pr.cnt == -1){
		tree[si].mx = tree[si * 2].mx;
		tree[si].cnt = tree[si * 2].cnt;
		tree[si].pos = tree[si * 2].pos;
	}
	else{
		tree[si].mx = max(tree[si * 2].mx, tree[si * 2 + 1].mx);
		tree[si].cnt = tree[si * 2].cnt + pr.cnt;
		tree[si].pos = tree[si * 2 + 1].pos;
	}
}
 
int main(){
	long N, Q;
	cin >> N >> Q;
	for (long i = 1; i <= N; ++i)
		cin >> v[i];
	build(1, N, 1);
	for (long i = 1; i <= Q; ++i)
	{
		long op, pos, k;
		cin >> op >> pos >> k;
		if (op == 1){
			node e = query(getmx(pos, 1, N, 1) + 1, k, pos, pos, N, 1, N, 1);
			if (e.cnt == -1)
				cout << pos << "\n";
			else
				cout << e.pos << "\n";
		}
		else{
			long val;
			cin >> val;
			update(pos, k, 1, N, val, 1);
		}
	}
	return 0;
}
 
/*int main() {
	int t, sqrtN;
	cin >> t;
	long n, q, idx, x, l, r, res;
	char typ;
	stack<long> s;
	while(t--){
		scanf("%ld %ld", &n, &q);
		for(long i = 0; i < n; i++)
			scanf("%ld", &a[i]);
		process(n);
		sqrtN = (int)(sqrt(n) + 0.0001);
		for(long i = 0; i < q; i++){
			cin >> typ;
			if(typ == '+'){
				scanf("%ld %ld", &idx, &x);
				idx--;
				a[idx] += x;
				
				// update bucket
				s = stack<long>();
				for(int j = min(1L * sqrtN - 1, n - sqrtN * (idx / sqrtN) - 1); j >= 0; j--){
					while(!s.empty() && a[s.top()] <= a[(idx / sqrtN) * sqrtN + j])
						s.pop();
					if(s.empty()){
						nxt2[(idx / sqrtN) * sqrtN + j] = -1;
						cnt[(idx / sqrtN) * sqrtN + j] = 0;
					} else {
						nxt2[(idx / sqrtN) * sqrtN + j] = nxt2[s.top()] == -1 ? s.top() : nxt2[s.top()];
						cnt[(idx / sqrtN) * sqrtN + j] = cnt[s.top()] + 1;
					}
					s.push((idx / sqrtN) * sqrtN + j);
				}
					
				l = nxt[idx];
				while(l != -1 && a[idx] >= a[l]){
					if(nxt2[l] == -1 || a[nxt2[l]] > a[idx]){
						if(nxt[l] == -1){
							l = -1;
							break;
						}
						else
							l = nxt[l];		
					}
					else
						l = nxt2[l];
				}
				nxt[idx] = l;
			}
			else{
				scanf("%ld %ld %ld", &idx, &l, &r);
				idx--;
				res = 0;
				while(idx != -1 && a[idx] < r){
					if(nxt2[idx] == -1 || a[nxt2[idx]] >= r || a[nxt2[idx]] < l){
						if(a[idx] >= l)
							res++;
						idx = nxt[idx];
					}
					else{
						res += cnt[idx];
						idx = nxt2[idx];
					}
				}
				if(idx != -1)
					res++;
				printf("%ld\n", res);
			}
		}
	}	
    return 0;
}*/