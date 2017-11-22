#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int d[MAX];

int main(){
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	sort(d, d + n);
	int i = 0;
	for(; i < n && d[i] < x; i++);
	if(i == n){
		cout << (x - i);
	}
	else if(d[i] == x){
		cout << (x - i + 1);
	}
	else{
		cout << (x - i);
	}
	return 0;
}
