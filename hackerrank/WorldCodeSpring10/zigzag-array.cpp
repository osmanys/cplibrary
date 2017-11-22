#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, a, d, m, r = 0;
	scanf("%d", &n);
	scanf("%d", &a);
	m = 0;
	for(int i = 0; i < n - 1; i++){
		scanf("%d", &d);
		if(a < d && m >= 0){
			m++;
		}
		else if(a > d && m <= 0){
			m--;
		}
		else{
			if(abs(m) > 1)
				r += abs(m) - 1;
			m = a < d ? 1 : -1;
		}
		a = d;
	}
	if(abs(m) > 1)
		r += abs(m) - 1;
	if(n < 3)
		printf("%d", 0);
	else
		printf("%d", r);
	
	return 0;
}
