#include <bits/stdc++.h>
#define L (1L << 18)

using namespace std;
vector<long> r;

int main(){
	long n, x, t;
	scanf("%ld %ld", &n, &x);
	if(n == 1)
		r.push_back(x);
	else if(n == 2){
		if(x == 0){
			printf("NO");
			return 0;
		}
		r.push_back(L);
		r.push_back(L + x);		
	}
	else{
		if((n - 2) % 4 == 0)
			t = n - 2;
		else if((n - 2) % 4 == 1)
			t = 1;
		else if((n - 2) % 4 == 2)
			t = n - 1;
		else
			t = 0;
		if(x == t){
			for(long i = 0; i < n - 2; i++)
				r.push_back(i);
			r.push_back(L);
			r.push_back(L ^ (n - 2));
		}
		else{
			for(long i = 1; i < n - 1; i++)
				r.push_back(i);
			r.push_back(L ^ x);
			r.push_back(L ^ t);		
		}
	}
	printf("YES\n");
	long tt = 0;
	for(vector<long>::iterator it = r.begin(); it != r.end(); it++){
		printf("%ld ", *it);
		tt ^= *it;
	}//printf("\n%ld", tt);
	return 0;
}
