#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, s, d;
	cin >> n;
	long t, c = 1;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &s, &d);
		if(s > c)
			c = s;
		else{
			t = (c - s) / d + ((c - s) % d > 0);
			c = s + t * d;
		}
		c++;
	}
	cout << (c - 1);
	return 0;
}
