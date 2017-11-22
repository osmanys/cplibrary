#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	scanf("%d", &n);
	cin >> s;
	int c = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			printf("%d", c);
			c = 0;
		}
		else
			c++;
	}
	printf("%d", c);
	return 0;
}
