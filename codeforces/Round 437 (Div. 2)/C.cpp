#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
long d[MAX][3];
vector<pair<long, long> > diff1;
vector<pair<long, long> > diff2;

int main(){
	long n, s, k, r1, r2, t;
	long long t1 = 0, t2 = 0, r = 0, s1, s2;
	cin >> n >> s;
	for(long i = 0; i < n; i++){
		scanf("%ld %ld %ld", &d[i][0], &d[i][1], &d[i][2]);
		if(d[i][1] > d[i][2]){			
			diff1.push_back(make_pair(abs(d[i][1] - d[i][2]), i));
			t1 += d[i][0];
		}
		else{			
			diff2.push_back(make_pair(abs(d[i][1] - d[i][2]), i));
			t2 += d[i][0];
		}
	}
	sort(diff1.begin(), diff1.end());
	long c1 = diff1.size() - 1;
	r1 = 0;
	while(t1 >= s || (t1 && r1)){
		k = diff1[c1].second;
		if(t1 >= s){
			r += d[k][0] * d[k][1];
			t1 -= d[k][0];
			r1 = (s + r1 - d[k][0]) % s;
			d[k][0] = 0;
			c1--;
		}
		else{
			r += min(d[k][0], r1) * d[k][1];
			t1 -= min(d[k][0], r1);
			t = r1;
			r1 -= min(d[k][0], r1);
			d[k][0] -= min(d[k][0], t);
			if(!d[k][0])
				c1--;
		}
	}
	sort(diff2.begin(), diff2.end());
	long c2 = diff2.size() - 1;
	r2 = 0;
	while(t2 >= s || (t2 && r2)){
		k = diff2[c2].second;
		if(t2 >= s){
			r += d[k][0] * d[k][2];
			t2 -= d[k][0];
			r2 = (s + r2 - d[k][0]) % s;
			d[k][0] = 0;
			c2--;
		}
		else{
			r += min(d[k][0], r2) * d[k][2];
			t2 -= min(d[k][0], r2);
			t = r2;
			r2 -= min(d[k][0], r2);
			d[k][0] -= min(d[k][0], t);
			if(!d[k][0])
				c2--;
		}
	}
	if(r1){
		
	}
	else if(r2){
		
	}
	else if(t1 + t2 > s){
		while(t1 > 0){
			k = diff1[c1].second;
			r += d[k][0] * d[k][1];
			t1 -= d[k][0];
			d[k][0] = 0;
			c1--;
		}
		while(t2 > 0){
			k = diff2[c2].second;
			r += d[k][0] * d[k][2];
			t2 -= d[k][0];
			d[k][0] = 0;
			c2--;
		}
	}
	else{
		s1 = 0;s2 = 0;
		for(long i = 0; i <= c1; i++){			
			k = diff1[i].second;
			s1 += d[k][1];
			s2 += d[k][2];
		}
		for(long i = 0; i <= c2; i++){			
			k = diff2[i].second;
			s1 += d[k][1];
			s2 += d[k][2];
		}
		if(s1 > s2){
			while(t1 > 0){
				k = diff1[c1].second;
				r += d[k][0] * d[k][1];
				t1 -= d[k][0];
				d[k][0] = 0;
				c1--;
			}
			while(t2 > 0){
				k = diff2[c2].second;
				r += d[k][0] * d[k][1];
				t2 -= d[k][0];
				d[k][0] = 0;
				c2--;
			}
		}
		else{
			while(t1 > 0){
				k = diff1[c1].second;
				r += d[k][0] * d[k][2];
				t1 -= d[k][0];
				d[k][0] = 0;
				c1--;
			}
			while(t2 > 0){
				k = diff2[c2].second;
				r += d[k][0] * d[k][2];
				t2 -= d[k][0];
				d[k][0] = 0;
				c2--;
			}			
		}
	}
	cout << r;
	return 0;
}
