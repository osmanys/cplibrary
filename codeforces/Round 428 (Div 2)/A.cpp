#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, c, d = 1, sc = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> c;
		if(c + sc >= 8){
			k -= 8;
			sc += c - 8;
		}
		else{
			k -= c + sc;
			sc = 0;
		}
		if(k <= 0){
			cout << d;
			return 0;
		}
		d++;
	}
	cout << -1;
	return 0;
}
