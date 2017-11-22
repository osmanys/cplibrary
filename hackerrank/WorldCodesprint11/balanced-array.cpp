#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t, sum1 = 0, sum2 = 0;
	cin >> n;
	for(int i = 0; i < n / 2; i++){
		cin >> t;
		sum1 += t;
	}
	for(int i = n / 2; i < n; i++){
		cin >> t;
		sum2 += t;
	}
	cout << abs(sum1 - sum2) << endl;
	
	return 0;
}
