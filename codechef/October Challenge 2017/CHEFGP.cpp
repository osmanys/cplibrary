#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	string s;
	long a, b, x, y, p;
	char ac, bc;
	cin >> t;
	while(t--){
		getline(cin, s);
		getline(cin, s);
		a = 0;b = 0;
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(*it == 'a')
				a++;
			else if(*it == 'b')
				b++;
		}
		cin >> x >> y;
		ac = 'a';bc = 'b';
		if(a < b){
			swap(a, b);
			swap(ac, bc);
			swap(x, y);
		}
		while((a - b) && b){
			p = (a - b + 1 > x) ? x : (a - b + 1);
			for(long i = 0; i < p; i++)
				printf("%c", ac);
			a -= p;
			printf("%c", bc);
			b--;
		}
		if(b){
			while(a && b){
				printf("%c", ac);
				a--;
				printf("%c", bc);
				b--;				
			}
		}
		else{
			while(a){
				p = (a > x) ? x : a;
				for(long i = 0; i < p; i++)
					printf("%c", ac);
				a -= p;
				if(a)
					printf("*");				
			}
		}
		printf("\n");
	}
    return 0;
}
