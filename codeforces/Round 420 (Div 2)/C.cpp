#include <bits/stdc++.h>

using namespace std;
long data[300000];

int main(){
	long n, d, count = 0, total = 0, total_ordered = 0, current = 1;
	string c;
	scanf("%ld", &n);
	for(long i = 0; i < 2 * n; i++){
		cin >> c;
		if(c == "add"){
			scanf("%ld", &d);
			data[total] = d;
			total++;
		}
		else{
			if(total_ordered < total && data[total - 1] != current){
				count++;
				total_ordered = total;
			}
			total--;
			if(total < total_ordered)
				total_ordered = total;
			current++;
		}
	}
	printf("%ld", count);
	return 0;
}
