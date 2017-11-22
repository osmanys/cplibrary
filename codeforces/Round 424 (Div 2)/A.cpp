#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d, s = 0, b = 0;
	scanf("%d", &n);
	int i = 0;
	for(; i < n; i++){
		scanf("%d", &d);
		if(s == 0){
			if(b == d)
				s = 1;
			else if(b > d)
				s =2;
		}
		else if(s == 1){
			if(b < d){
				printf("NO");
				break;
			}
			else if(b > d)
				s = 2;
		}
		else{
			if((b < d) || (b == d)){
				printf("NO");
				break;
			}
		}
		b = d;
	}
	if(i == n)
		printf("YES");
	return 0;
}
