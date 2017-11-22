#include <bits/stdc++.h>

using namespace std;

int main(){
	long a, b, f, k;
	cin >> a >> b >> f >> k;
	long fuel = b, r = 0;
	for(long i = 0; i < k; i++){
		if(fuel - f < 0){
			if(i == 0){
				r = -1;
				break;
			}
		}
		fuel -= f;
		if(fuel - a < 0){
			r++;
			fuel = b;
		}
		fuel -= a;
		if(fuel - f < 0){
			r = -1;
			break;
		}
		else
			fuel -= f;
	}
	return 0;
}
