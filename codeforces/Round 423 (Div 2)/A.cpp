#include <bits/stdc++.h>

using namespace std;

int main(){
	long n, t1, t21 = 0, t2, d = 0;
	int g;
	scanf("%ld %ld %ld", &n, &t1, &t2);
	for(long i = 0; i < n; i++){
		scanf("%d", &g);
		if(g == 1){
			if(t1){
				t1--;
			}
			else if(t2){
				t2--;
				t21++;
			}
			else if(t21){
				t21--;
			}
			else{
				d++;
			}
		}
		else if(t2){
			t2--;
		}
		else{
			d += 2;
		}
	}
	printf("%ld", d);
	return 0;
}
