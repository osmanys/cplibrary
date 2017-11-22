#include <bits/stdc++.h>

using namespace std;

struct Pick{
	long max;
	long down;
};

int main(){
	int t;
	long n, h, up, max;
	vector<Pick> picks;
	long long total;
	bool upload;
	cin >> t;
	while(t--){
		cin >> n;
		max = 0;
		up = 0;
		total = 0;
		picks.clear();
		for(long j = 0; j < n; j++){
			cin >> h;
			total += h;
			if(h > up){
				up++;
				upload = true;
			}
			else{
				if(upload && (up > max)){
					if(up > 1){
						Pick p;
						p.down = up;
						p.max = up;
						picks.push_back(p);
					}
					else
						max = 1;
				}
				up = h;
				upload = false;
			}
			for(long i = 0; i < picks.size();){
				/*if(max >= picks[i].max){
					picks.erase(picks.begin() + i);
					continue;
				}*/
				picks[i].down--;
				if(h < picks[i].down){
					picks[i].max -= (picks[i].down - h) / 2 + (picks[i].down - h) % 2; 
					/*if(picks[i].max <= max){
						picks.erase(picks.begin() + i);
						continue;
					}*/
					picks[i].down = h;	
				}
				if(picks[i].down <= 1 && max < picks[i].max){
					max = picks[i].max;
					picks.erase(picks.begin() + i);
					continue;
				}
				i++;
			}
		}
		if(up > max){
			Pick p;
			p.down = up;
			p.max = up;
			picks.push_back(p);
		}
		for(long i = 0; i < picks.size(); i++){
			if(max < picks[i].max - ((picks[i].down - 1) / 2 + (picks[i].down - 1) % 2))
				max = picks[i].max - ((picks[i].down - 1) / 2 + (picks[i].down - 1) % 2);
		}
		cout << (total - max * max) << endl;
	}
	return 0;
}
