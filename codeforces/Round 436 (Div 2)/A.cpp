#include <bits/stdc++.h>
#define MAX 101

using namespace std;
int d[MAX];

int main(){
	int n, t;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		d[t]++;
	}
	int r1 = -1, r2 = -1;
	for(int i = 0; i < MAX; i++){
		if(d[i]){
			if(r1 == -1)
				r1 = i;
			else if(r2 == -1)
				r2 = i;
			else{
				r1 = -1;
				r2 = -1;
				break;
			}
		}
	}
	printf((r1 == -1 || r2 == -1) ? "NO" : "YES\n%d %d", r1, r2);
	return 0;
}
