#include <bits/stdc++.h>
#define MAX 101

using namespace std;
bool t[MAX];

int main(){
	int n, x, d;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> d;
		t[d] = true;
	}
	int r = t[x];
	for(int i = 0; i < x; i++)
		if(!t[i])
			r++;
	cout << r;
	return 0;
}
