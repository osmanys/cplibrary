#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	long q, c, up, down;
	char b = 0;
	string s;
	scanf("%ld", &q);
	while(q--){
		cin >> s;
		c = 0;
		up = 0;
		down = 0;
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(*it == '>'){
				if(b == '>')
					c++;
				else
					c = 1;
				if(up < c)
					up = c;
				b = '>';
			}
			else if(*it == '<'){
				if(b == '<')
					c++;
				else
					c = 1;
				if(down < c)
					down = c;
				b = '<';
			}
		}
		printf("%ld\n", max(up, down) + 1);
	}
    return 0;
}
