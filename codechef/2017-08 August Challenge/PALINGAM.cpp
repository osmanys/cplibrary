#include <bits/stdc++.h>
 
using namespace std;
int a[26], b[26];
 
int main() {
	int T;
	string s, t;
	bool winA, beginA, beginB;
	scanf("%d\n", &T);
	while(T--){
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		getline(cin, s);
		for(string::iterator it = s.begin(); it != s.end(); it++)
			a[(*it) - 'a']++;
		getline(cin, t);
		for(string::iterator it = t.begin(); it != t.end(); it++)
			b[(*it) - 'a']++;
		winA = false;
		beginA = false;
		beginB = false;
		for(int i = 0; i < 26; i++){
			if(a[i] > 1 && !b[i]){
				winA = true;
				break;
			}
			if(a[i] == 1 && !b[i]){
				beginA = true;
			}
			if(b[i] && !a[i])
				beginB = true;
		}
		if(winA || (beginA && !beginB))
			printf("A\n");
		else
			printf("B\n");
	}
    return 0;
}
