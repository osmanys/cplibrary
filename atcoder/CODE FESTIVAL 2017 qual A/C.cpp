#include <bits/stdc++.h>

using namespace std;
int d[26];

int main(){
	int h, w;string s;
	cin >> h >> w;
	getline(cin, s);
	for(int i = 0; i < h; i++){
		getline(cin, s);
		for(int j = 0; j < w; j++){
			d[s[j] - 'a']++;
		}
	}
	int d4 = 0, even = 0, odd = 0;
	for(int i = 0; i < 26; i++){
		if(d[i] % 4 == 0)
			d4++;
		else if(d[i] % 2 == 0)
			even++;
		else
			odd++;
	}
	if((h & 1) && (w & 1)){
		if(odd == 1 && even < (h + w) / 2)
			cout << "Yes";
		else
			cout << "No";
	}
	else if((h & 1) || (w & 1)){
		if(odd == 0 && even <= (h & 1) * w / 2 + (w & 1) * h / 2)
			cout << "Yes";
		else
			cout << "No";
	}
	else{
		if(odd == 0 && even == 0)
			cout << "Yes";
		else
			cout << "No";		
	}
	return 0;
}
