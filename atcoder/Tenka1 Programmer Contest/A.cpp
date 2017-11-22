#include <bits/stdc++.h>

using namespace std;

int main(){
	long long N;
	cin >> N;
	long w, h, n, mh, mn;
	bool found = false;
	for(h = 1; h <= 3500 && !found; h++){
		for(n = h; n <= 3500 && !found; n++){
			if((4 * h * n - N * n - N * h) && !((N * h * n) % (4 * h * n - N * n - N * h))){
				if(w <= 3500){
					found = true;
					w = (N * h * n) / (4 * h * n - N * n - N * h);
					break;
				}
			}
		}
	}
	h--;
	found = false;
	for(mh = 1; mh <= 3500 && !found; mh++){
		for(mn = 1; mn <= 3500 && !found; mn++){
			if((4 * mh * h * mn * n - N * mn * n - N * mh * h) && !((N * mh * h * mn * n) % (4 * mh * h * mn * n - N * mn * n - N * mh * h))){
				w = (N * mh * h * mn * n) / (4 * mh * h * mn * n - N * mn * n - N * mh * h);
				if(w > 0){
					found = true;
					break;
				}
			}
		}
	}
	mh--;
	if(!found){
		mh = 1;
		mn = 1;
	}
	w = (N * mh * h * mn * n) / (4 * mh * h * mn * n - N * mn * n - N * mh * h);
	cout << 1LL * mh * h << " " << 1LL * mn * n << " " << w;
	return 0;
}
