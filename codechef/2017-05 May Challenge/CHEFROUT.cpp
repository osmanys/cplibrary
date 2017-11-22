#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	string s;
	char b;
	scanf("%d\n", &t);
	while(t--){
		getline(cin, s);
		b = 0;
		string::iterator it = s.begin();
		for(; it != s.end(); it++){
			if((*it == 'E' && b == 'S') || (*it == 'C' && (b == 'E' || b == 'S')))
				break;
			b = *it;
		}
		if(it == s.end())
			printf("yes\n");
		else
			printf("no\n");
	
	}
	
	return 0;
}
