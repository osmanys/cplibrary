#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int d[MAX];

int main(){
	int n, m;bool valid = true;
	cin >> n;
	cin >> d[0];
	cin >> d[1];
	m = d[1] - d[0];
	for(int i = 2; i < n; i++){
		cin >> d[i];
		if(valid && m != d[i] - d[i - 1])
			valid = false;
	}
	cout << (valid ? d[n - 1] + m : d[n - 1]);
	return 0;
}
