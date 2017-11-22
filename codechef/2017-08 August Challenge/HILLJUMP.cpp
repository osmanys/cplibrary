#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;
vector<bitset<MAX> > d;
 
int main() {
	int t;
	long n, q, c, p, b;
	long long r;
	char tp;
	bool s, carry;
	bitset<MAX> tmp;
	scanf("%d", &t);
	while(t--){
		scanf("%ld %ld", &n, &q);
		scanf("%c", &tp);
		r = 0;
		b = -1;
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
					b = 0;
				}
				else{
					tmp = d[b];
					carry = 1;
					for(long j = c; j < n && carry; j++){
						s = tmp[i] ^ carry;
						carry = tmp[j] && carry;
						tmp[j] = s;
					}
					p = lower_bound(d.begin(), d.end(), tmp) - d.begin();
					if(p == n){
						
					}
					else{
						if((d[p] ^ tmp).none()){
							
						}
						else{
							
						}
					}
				}
			}
			scanf("%c", &tp);
		}
	}
    return 0;
}
