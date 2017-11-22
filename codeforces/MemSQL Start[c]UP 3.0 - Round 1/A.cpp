#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	cin >> k;
	long d, m = 0;
	for(int i = 0; i < k; i++){
		cin >> d;
		if(d > m)
			m = d;
	}
	cout << ((m > 25) ? m - 25 : 0);
	return 0;
}
