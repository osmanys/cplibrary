#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d;
	long long k;
	cin >> n >> k;
	cin >> d;
	int w = 0, c = d;
	for(int i = 1; i < n; i++){
		cin >> d;
		if(c > d){
			w++;
			if(w >= k){
				cout << c;
				return 0;
			}
		}
		else{
			w = 1;
			c = d;
		}
	}
	cout << c;
	return 0;
}
