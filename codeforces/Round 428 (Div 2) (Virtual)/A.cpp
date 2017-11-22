#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int d[MAX];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> d[i];
	int i = 0;
	for(; i < n && k > 0; i++){
		if(d[i] >= 8){
			k -= 8;
		}
		else{
			k -= d[i];			
		}
	}
	cout << (k <= 0 ? i : -1);
	return 0;
}
