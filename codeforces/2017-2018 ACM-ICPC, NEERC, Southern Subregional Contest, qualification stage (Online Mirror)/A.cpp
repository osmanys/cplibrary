#include <bits/stdc++.h>
#define MAX 101

using namespace std;
int l[MAX], r[MAX];
vector<int> l0, t;

int main(){
	int n, c;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		if(!l[i])
			l0.push_back(i);
	}
	for(vector<int>::iterator it = l0.begin(); it != l0.end(); it++){
		c = *it;
		t.push_back(c);
		while(r[c])
			c = r[c];
		t.push_back(c);
	}
	for(int i = 1; i + 1 < t.size(); i += 2){
		r[t[i]] = t[i + 1];
		l[t[i + 1]] = t[i];
	}
	for(int i = 1; i <= n; i++)
		cout << l[i] << " " << r[i] << "\n";
	return 0;
}
