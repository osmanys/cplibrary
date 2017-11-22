#include <bits/stdc++.h>

using namespace std;
int l[26];

int main(){
	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	int c = 0;
	for(string::iterator it1 = s1.begin(); it1 != s1.end(); it1++){
		l[(*it1) - 'a'] = c;
		c++;
	}	
	char ch;
	for(string::iterator it = s3.begin(); it != s3.end(); it++){
		if((*it) < 65)
			ch = *it;
		else
			ch = s2[l[((*it) - 'a' < 0) ? ((*it) - 'a' + 32) : ((*it) - 'a')]] - (((*it) - 'a' < 0) ? 32 : 0);
		cout << ch;
	}
	return 0;
}
