#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	vector<char> ch;
	vector<long> rng;
	long c = 0;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		if(*it != 'x'){
			ch.push_back(*it);
			rng.push_back(c);
			c = 0;
		}
		else
			c++;
	}
	rng.push_back(c);
	long sz = ch.size();
	for(long i = 0; i < sz / 2 + (sz & 1); i++){
		if(ch[i] != ch[sz - 1 - i]){
			cout << -1;
			return 0;
		}
	}
	long r = 0;
	sz = rng.size();
	for(long i = 0; i < sz / 2; i++)
		r += abs(rng[i] - rng[sz - 1 - i]);
	cout << r;
	return 0;
}
