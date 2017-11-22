#include <bits/stdc++.h>
 
using namespace std;
int p[26];
int q[26];
 
int main() {
	int t, sz, i;
	string a, b;
	scanf("%d", &t);
	while(t--){
		cin >> a >> b;
		memset(p, -1, sizeof p);
		memset(q, -1, sizeof q);
		sz = a.size();
		i = 0;
		for(; i < sz; i++){
			if(((p[a[i] - 'a'] == -1) || (p[a[i] - 'a'] == b[i] - 'a')) && ((q[b[i] - 'a'] == -1) || (q[b[i] - 'a'] == a[i] - 'a'))){
				p[a[i] - 'a'] = b[i] - 'a';
				q[b[i] - 'a'] = a[i] - 'a';
			}
			else
				break;
		}
		if(i < sz)
			printf("NO\n");
		else
			printf("YES\n");
	}
    return 0;
}
