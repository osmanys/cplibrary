#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, l, state;
	string s;
	scanf("%d", &t);
	while(t--){
		cin >> l;
		cin >> s;
		state = 0;
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(state == 0){
				if(*it == 'H')
					state = 1;
				else if(*it == 'T'){
					state = -1;
					break;
				}					
			}
			else if(state == 1){				
				if(*it == 'H'){
					state = -1;
					break;
				}
				else if(*it == 'T')
					state = 2;
			}
			else if(state == 2){				
				if(*it == 'H')
					state = 1;
				else if(*it == 'T'){
					state = -1;
					break;
				}
			}
		}
		if(state == 0 || state == 2)
			printf("Valid\n");
		else
			printf("Invalid\n");
	}
	
    return 0;
}
