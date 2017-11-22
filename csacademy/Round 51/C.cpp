#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long a, b, c, tm;
	while(t--){
		scanf("%ld %ld %ld", &a, &b, &c);
		if(a + b != c && a + c != b && b + c != a){
			printf("-1\n");
		}
		else{
			if(a + b != c){
				if(a + c == b){
					tm = c;
					c = b;
					b = tm;
				}
				else{
					tm = c;
					c = a;
					a = tm;
				}
			}
			printf("0 0 %ld %ld &ld &ld\n", a / 2, a - a / 2, a / 2 + b / 2, a + b - a / 2 - b / 2);
		}
	}
	
	return 0;
}
