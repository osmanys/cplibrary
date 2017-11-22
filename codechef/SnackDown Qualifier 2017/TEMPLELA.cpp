#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n, d, d0, i;
	bool valid;
	scanf("%d", &t);
	while(t--){
		cin >> n;
		valid = true;
		if(!(n&1))
			valid = false;
		d0 = 0;
		i = 0;
		for(; i <= n / 2; i++){
			cin >> d;
			if(d0 + 1 != d)
				valid = false;
			d0 = d;
		}
		for(; i < n; i++){
			cin >> d;
			if(d0 - 1 != d)
				valid = false;
			d0 = d;
		}
		if(i < n)
			valid = false;
		printf(valid ? "yes\n" : "no\n");
	}
	
    return 0;
}
