#include <bits/stdc++.h>

using namespace std;

int main(){
	char d[50];
	string s, t, m = "", cur;
	getline(cin, s);
	getline(cin, t);
	int c = 0;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		d[c] = *it;
		c++;
	}
	bool valid;
	int tz = t.size();
	for(int i = 0; i < c; i++){
		if(c - i >= tz){
			cur = "";
			valid = true;
			for(int j = 0; j < i; j++)
				cur += d[j];
			for(int j = i; j < c; j++){
				if(d[j] == '?' || j - i >= tz || d[j] == t[j - i]){
					if(j - i < tz)
						cur += t[j - i];
					else if(d[j] == '?')						
						cur += 'a';
					else
						cur += d[j];
				}
				else{
					valid = false;
					break;
				}
			}
			if(valid){
				if(m == "")
					m = cur;
				else if(m > cur)
					m = cur;
			}
		}
		if(d[i] == '?')
			d[i] = 'a';
	}	
	cout << (m == "" ? "UNRESTORABLE" : m);
	return 0;
}
