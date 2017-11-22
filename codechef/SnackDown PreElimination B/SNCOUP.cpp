#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long n, f;
	bool half, top, down, fence;
	string line1, line2;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> line1 >> line2;
		long i = 0;
		top = false;
		down = false;
		for(; i < n; i++){
			if(line1[i] == '*'){
				top = true;
				if(down)
					break;
			}
			if(line2[i] == '*'){
				down = true;
				if(top)
					break;
			}
		}
		half = (top && down);
		f = 0;
		top = false;
		down = false;
		for(int i = 0; i < n; i++){
			fence = false;
			if(line1[i] == '*'){
				if(top){
					fence = true;
					top = true;
					down = false;
				}
				else
					top = true;
			}
			if(line2[i] == '*'){
				if(down){
					fence = true;
					top = line1[i] == '*';
					down = true;
				}
				else
					down = true;
			}
			if(fence)
				f++;
		}
		cout << (f + half) << endl;
	}
	return 0;
}
