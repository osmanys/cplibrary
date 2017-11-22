#include <bits/stdc++.h>
#define fi "B-large-practice.in"
#define fo "B-large-practice.out"

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, changes;
    string s;
    char c;
    scanf("%d\n", &t);
    for(int i = 1; i <= t; i++){
    	getline(cin, s);
    	changes = 0;
    	c = '0';
    	for(string::iterator it = s.begin(); it < s.end(); it++){
    		if(c != *it){
    			changes++;
    			c = *it;
			}
		}
		if(s[s.length() - 1] == '+')
			changes--;
		printf("Case #%d: %d\n", i, changes);
	}
    
	return 0;
}
