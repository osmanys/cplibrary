#include<bits/stdc++.h>
#define MAX 1000001
#define MAXSZ (1 << 21)
 
using namespace std;
 
struct node{
	long long val, mx;
	long cnt, pos; 
	node(){
		val = 1 << 31;
		cnt = -1;
		pos = 0;
		mx = 0;
	}
};
 
node tree[MAXSZ];
long v[MAX];
long long lazy[MAXSZ];
 
node find(long long mx, long pos, long ss, long se, long si){
	if (lazy[si]){
		tree[si].val += lazy[si];
		if (ss != se){
			lazy[2 * si] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	long mid = (ss + se) / 2;
	if (ss == se){
		if (tree[si].val >= mx){
			tree[si].mx = tree[si].val;
			return tree[si];
		}
		else
			return node();
	}
	if (tree[si * 2].val + lazy[si * 2] < mx && tree[si * 2 + 1].val + lazy[si * 2 + 1] < mx)
		return node();
	if (tree[si * 2].val + lazy[si * 2] < mx || pos > mid)
		return find(mx, pos, mid + 1, se, si * 2 + 1);
	else if(pos <= mid){
		node pr = find(mx, pos, ss, mid, si * 2);
		if (pr.cnt == -1)
			return find(mx, pos, mid + 1, se, si * 2 + 1);
		else if (tree[si * 2 + 1].val + lazy[si * 2 + 1] > tree[si * 2].val + lazy[si * 2]){
			pr.cnt = tree[si].cnt - (tree[si * 2].cnt - pr.cnt);
			pr.mx = max(pr.mx, tree[si * 2 + 1].val);
		}
		return pr;
	}
}
 
void build(long ss, long se, long si){
	if (ss == se){
		tree[si].val = v[ss];
		tree[si].cnt = 1;
		tree[si].pos = ss;
		return;
	}
	long mid = (ss + se) / 2;
	build(ss, mid, si * 2);
	build(mid + 1, se, si * 2 + 1);
	node pr = find(tree[si * 2].val + 1, tree[si * 2].pos, mid + 1, se, si * 2 + 1);
	if (pr.cnt == -1){
		tree[si].val = tree[si * 2].val;
		tree[si].cnt = tree[si * 2].cnt;
		tree[si].pos = tree[si * 2].pos;
	}
	else{
		tree[si].val = max(tree[si * 2].val, tree[si * 2 + 1].val);
		tree[si].cnt = tree[si * 2].cnt + pr.cnt;
		tree[si].pos = tree[si * 2 + 1].pos;
	}
}
 
void update(long qs, long qe, long ss, long se, long val, long si){
	if (lazy[si]){
		tree[si].val += lazy[si];
		if (ss != se){
			lazy[2 * si] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (qs <= ss && se <= qe){
		tree[si].val += val;
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
	node pr = find(tree[si * 2].val + lazy[2 * si] + 1, tree[si * 2].pos, mid + 1, se, si * 2 + 1);
	if (tree[si * 2].val + lazy[si * 2] > tree[si * 2 + 1].val + lazy[si * 2 + 1] || pr.cnt == -1){
		tree[si].val = tree[si * 2].val + lazy[si * 2];
		tree[si].cnt = tree[si * 2].cnt;
		tree[si].pos = tree[si * 2].pos;
	}
	else{
		tree[si].val = tree[si * 2 + 1].val + lazy[si * 2 + 1];
		tree[si].cnt = tree[si * 2].cnt + pr.cnt;
		tree[si].pos = tree[si * 2 + 1].pos;
	}
}
 
node query(long long mn, long long mx, long &cnt, long pos, long qs, long qe, long ss, long se, long si){
	if (lazy[si]){
		tree[si].val += lazy[si];
		if (ss != se){
			lazy[2 * si] += lazy[si];
			lazy[2 * si + 1] += lazy[si];
		}
		lazy[si] = 0;
	}
	long mid = (ss + se) / 2;
	node e1 = node(), e2 = node();
	if (ss == se){
		if (tree[si].val < mn)
			return node();
		else{
			--cnt;
			return tree[si];
		}
	}
	if (qs <= ss && se <= qe){
		node pr1 = find(mn, pos, ss, mid, si * 2);
		long long cx = tree[si * 2].val + lazy[si * 2] + 1;
		long cz = tree[si * 2].pos;
		if (pr1.cnt == -1){
			pr1.cnt = 0;
			cx = mn;
			cz = pos;
		}
		node pr2 = find(cx, cz, mid + 1, se, si * 2 + 1);
		if (mx <= pr1.mx)
			return query(mn, mx, cnt, pos, qs, qe, ss, mid, si * 2);
		else if (mx <= pr2.mx){
			cnt -= pr1.cnt;
			return query(cx, mx, cnt, cz, qs, qe, mid + 1, se, si * 2 + 1);
		}
		else{
			if (pr2.cnt == -1){
				pr2.cnt = 0;
				if (!pr1.cnt)
					return node();
				else{
					e1.val = tree[si * 2].val + lazy[si * 2];
					e1.cnt = pr1.cnt;
					e1.pos = tree[si * 2].pos;
				}
			}
			else{
				e1.val = tree[si * 2 + 1].val + lazy[si * 2 + 1];
				e1.cnt = pr1.cnt + pr2.cnt;
				e1.pos = tree[si * 2 + 1].pos;
			}
			cnt -= pr1.cnt + pr2.cnt;
			return e1;
		}
	}
	if (qs <= mid)
		e1 = query(mn, mx, cnt, pos, qs, qe, ss, mid, si * 2);
	if (qe > mid && (e1.cnt == -1 || e1.val < mx)){
		if (e1.cnt == -1)
			e2 = query(mn, mx, cnt, pos, qs, qe, mid + 1, se, si * 2 + 1);
		else
			e2 = query(e1.val + 1, mx, cnt, e1.pos, qs, qe, mid + 1, se, si * 2 + 1);
	}
	if (e1.cnt != -1 && e2.cnt != -1){
		e2.cnt += e1.cnt;
		return e2;
	}
	if (e1.cnt != -1)
		return e1;
	else if (e2.cnt != -1)
		return e2;
	return node();
}

int main() {
	int t;
	cin >> t;
	long n, q, idx, x, l, r, res;
	char typ;
	stack<long> s;
	while(t--){
		scanf("%ld %ld", &n, &q);
		for(long i = 1; i <= n; i++)
			scanf("%ld", &v[i]);
		build(1, n, 1);
		for(long i = 0; i < q; i++){
			cin >> typ;
			if(typ == '+'){
				scanf("%ld %ld", &idx, &x);
				update(idx, idx, 1, n, x, 1);
			}
			else{
				scanf("%ld %ld %ld", &idx, &l, &r);
				node f = find(l, idx, 1, n, 1);
				if(f.cnt == -1)
					printf("0\n");
				else if(f.val >= r)
					printf("1\n");
				else{
					long k = LONG_MAX;
					node e = query(f.val + 1, r, k, f.pos, f.pos, n, 1, n, 1);
					printf("%ld\n", e.cnt == -1 ? 1 : (LONG_MAX - k + 1));
				}
			}
		}
	}	
    return 0;
}
