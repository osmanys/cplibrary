#include <bits/stdc++.h>

using namespace std;
long c[26][100001];
long last[26];
vector<pair<char, long> > seq;

int main(){
	string s;
	long k, sz;
	cin >> s >> k;
	sz = s.size();
	memset(last, -1, sizeof last);
	for(long i = 1; i <= sz; i++){
		for(int j = 0; j < 26; j++){
			if(j == s[i - 1] - 'a')
				c[j][i] = c[j][i - 1] + 1;
			else
				c[j][i] = c[j][i - 1];
		}
		last[s[i - 1] - 'a'] = i;
	}
	long l = 0;
	for(int j = 25; j >= 0; j--){
		if(c[j][sz] - c[j][l] >= k){
			seq.push_back(make_pair(j + 'a', c[j][sz] - c[j][l]));
			l = last[j];
		}
	}
	string r = "";
	for(vector<pair<char, long> >::iterator it = seq.begin(); it != seq.end(); it++){
		for(long i = 0; i < (*it).second; i++)
			r += (*it).first;
	}
	cout << r;
	return 0;
}
