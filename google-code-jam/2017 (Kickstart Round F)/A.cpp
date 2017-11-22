#include <bits/stdc++.h>
#define fi "A.in"
#define fo "A.out"
#define MAX 10000

using namespace std;
int d[MAX];

bool solve(int s, int f, int n){
	if(s == f)
		return true;
	int c;
	if((n & 1 && ((n - f + s) & 1)) || !(n & 1 || ((n - f + s) & 1)))
		c = (n - 1) / 2 + (n - f + s) / 2;
	else
		c = (n - 1) / 2 - (n - f + s) / 2;
	return (d[c] == s && solve(s + 1, f, n)) || (d[c] == f && solve(s, f - 1, n));	
}

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &d[i]);
		printf("%s\n", solve(1, n, n) ? "YES" : "NO");
	}
    
	return 0;
}
