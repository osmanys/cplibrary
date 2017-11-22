#include <bits/stdc++.h>
#define fi "A-large.in"
#define fo "A-large.out"
#define MAX 1000

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, k, n, c, r;
    string s;
    bool flip[MAX];
    scanf("%d\n", &t);
    for(int i = 1; i <= t; i++){
    	printf("Case #%d: ", i);
    	cin >> s >> k;
    	n = s.length();
    	for(int j = 0; j < n; j++){
    		if(s[j] == '+')
    			flip[j] = true;
    		else
    			flip[j] = false;
		}
		c = 0;
		for(int j = 0; j < n - k + 1; j++){
			if(!flip[j]){
				for(int t = j; t < j + k; t++)
					flip[t] = !flip[t];
				c++;
			}
		}
		r = n - k;
		for(;r < n; r++){
			if(!flip[r])
				break;
		}
		if(r == n)
			printf("%d\n", c);
		else
			printf("%s\n", "IMPOSSIBLE");
	}
    
	return 0;
}
