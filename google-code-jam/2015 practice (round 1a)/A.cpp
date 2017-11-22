#include <bits/stdc++.h>
#define fi "A-large-practice.in"
#define fo "A-large-practice.out"

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n, m, bm, i;
    long c1, c2, dc;
    vector<int> c;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		scanf("%d", &n);
		c1 = 0;
		i = 1;
		c.clear();
		scanf("%d", &m);
		c.push_back(m);
		bm = m;
		dc = 0;
		while(i++ < n){
			scanf("%d", &m);
			c.push_back(m);
			if(bm > m)
				c1 += bm - m;
			if(dc < bm - m)
				dc = bm - m;
			bm = m;
		}
		c2 = 0;
		for(vector<int>::iterator it = c.begin(); it != c.end(); it++){
			bm = ((*it > dc) ? dc : *it);
			c2 += bm;
		}
		printf("%ld %ld\n", c1, c2 - bm);
	}
    
	return 0;
}
