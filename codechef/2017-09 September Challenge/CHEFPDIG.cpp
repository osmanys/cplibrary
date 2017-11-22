#include <bits/stdc++.h>
 
using namespace std;
int dig[10];
 
int main() {
	int t;
	string l;
	scanf("%d", &t);
	getline(cin, l);
	while(t--){
		getline(cin, l);
		memset(dig, 0, sizeof dig);
		for(string::iterator it = l.begin(); it != l.end(); it++)
			dig[*it - '0']++;
		for(int i = 65; i < 91; i++){
			if((i / 10 == i % 10 && dig[i / 10] > 1) || (i / 10 != i % 10 && dig[i / 10] && dig[i % 10]))
				printf("%c", i);
		}
		printf("\n");
	}
    return 0;
}
