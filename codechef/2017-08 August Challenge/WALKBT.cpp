#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;
vector<bitset<MAX> > d;
vector<long> sb;
 
int main() {
	int t;
	long n, q, c, p, b, j, _sb, sz, minj, minsb;
	long long r;
	char tp;
	bool s, carry;
	bitset<MAX> tmp;
	scanf("%d", &t);
	while(t--){
		scanf("%ld %ld", &n, &q);
		scanf("%c", &tp);
		b = -1;
		d.clear();
		sb.clear();
		for(long i = 0; i < q; i++){
			scanf("%c", &tp);
			if(tp == '?')
				cout << r << "\n";
			else{
				scanf("%ld", &c);
				if(b == -1){
					tmp = 0;
					tmp[c] = 1;
					d.push_back(tmp);
					sb.push_back(c);
					b = 0;
					r = n + 1;
					minsb = c;
				}
				else{
					tmp = d[b];
					carry = 1;
					for(j = c; j < n && carry; j++){
						s = tmp[j] ^ carry;
						carry = tmp[j] && carry;
						tmp[j] = s;
					}
					if(!carry)
						_sb = max(j - 1, sb[b]);
					else
						for(_sb = c - 1; _sb >= 0 && !tmp[_sb]; _sb--);
					p = lower_bound(sb.begin(), sb.end(), _sb) - sb.begin();
					sz = sb.size();
					if(p == sz){
						d.push_back(tmp);
						sb.push_back(_sb);
						b = d.size() - 1;
						r += j;
					}
					else{
						minj = n + 1;
						while(p < sz && sb[p] == _sb){
							if(d[p] == tmp)
								break;
							for(j = _sb; j >= 0 && d[p][j] == tmp[j]; j--);
							if(j + 1 < minj)
								minj = j + 1;
							p++;
						}
						if(p == sz || (p && d[p] != tmp))
							p--;
						if(sb[p] != _sb)
							minj = max(minsb, _sb) + 1;
						if(d[p] != tmp){
							d.insert(d.begin() + p, tmp);
							sb.insert(sb.begin() + p, _sb);
							r += minj;
							if(minsb > _sb)
								minsb = _sb;
						}
						b = p;
					}
				}
			}
			scanf("%c", &tp);
		}
	}
    return 0;
}
