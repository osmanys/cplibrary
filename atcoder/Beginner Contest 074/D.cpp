#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long r = 0;
	scanf("%d", &n);
	long d[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%ld", &d[i][j]);
	bool exist, fail = false;
	for(int i = 0; i < n && !fail; i++)
		for(int j = 0; j < n && !fail; j++){
			exist = true;
			for(int k = 0; k < n && !fail; k++){
				if(i != j && i != k && j != k){
					if(d[i][j] > d[i][k] + d[j][k])
						fail = true;
					else if(d[i][j] == d[i][k] + d[j][k])
						exist = false;
				}
			}
			if(exist)
				r += d[i][j];
		}
	cout << (fail ? -1 : r / 2);
	return 0;
}
