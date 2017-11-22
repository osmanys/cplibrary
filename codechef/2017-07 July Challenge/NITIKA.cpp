#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int q, c;
	string s;
	string f[3], r[3];
	scanf("%d", &q);
	getline(cin, s);
	while(q--){
		getline(cin, s);
		c = 0;
		f[0] = f[1] = f[2] = r[0] = r[1] = r[2] = "";
		for(string::iterator it = s.begin(); it != s.end(); it++){
			if(*it == ' '){
				c++;
			}
			else if(f[c].size() == 0){
				if(*it > 90){
					f[c] += *it - 32;
					r[c] += *it - 32;
				}
				else{
					f[c] += *it;
					r[c] += *it;
				}
			}
			else{
				if(f[c].size() == 1){
					r[c] += '.';
				}
				if(*it <= 90){
					f[c] += *it + 32;
				}
				else{
					f[c] += *it;
				}
			}
		}
		if(c == 0){
			printf("%s\n", f[0].c_str());
		}
		else if(c == 1){
			printf("%s %s\n", r[0].c_str(), f[1].c_str());
		}
		else{
			printf("%s %s %s\n", r[0].c_str(), r[1].c_str(), f[2].c_str());			
		}
	}
    return 0;
}
