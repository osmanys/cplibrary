#include <bits/stdc++.h>

using namespace std;
long ca[26], cb[26];
vector<char> r;

int main(){
	string a, b;
	int d = 0;
	cin >> a >> b;
	for(string::iterator it = a.begin(); it != a.end(); it++){
		if(*it == '?')
			d++;
		else
			ca[*it - 'a']++;
	}
	for(string::iterator it = b.begin(); it != b.end(); it++)
		cb[*it - 'a']++;	
	while(d > 0){
		for(int i = 0; i < 26; i++){
			if(ca[i] >= cb[i])
				ca[i] -= cb[i];
			else{
				for(int j = 0; j < cb[i] - ca[i]; j++){
					d--;
					r.push_back(i + 'a');
				}
				ca[i] = 0;
			}
		}
	}
	d = 0;
	for(string::iterator it = a.begin(); it != a.end(); it++){
		if(*it == '?')
			cout << r[d++];
		else
			cout << *it;
	}
	return 0;
}
