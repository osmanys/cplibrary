#include <bits/stdc++.h>
#define MAX 100

using namespace std;
double t[MAX], v[MAX];

int main(){
	int n;
	double t0, tf, v0 = 0, d = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = n; i >= 0; i--){
		if(v[i] > v0)
			v[i] = min(v0 + t[i], v[i]);
		v0 = v[i];
	}
	v0 = 0;
	for(int i = 0; i < n - 1; i++){
		if(v[i] <= v[i + 1]){
			t0 = 0;
			if(v0 < v[i])
				t0 = min(t[i], v[i] - v0);
			d += v0 * t0 + t0 * t0 / 2;
			d += v[i] * (t[i] - t0);
			v0 += t0;
		}
		else{
			t0 = 0;
			if(v0 < v[i])
				t0 = min(t[i], v[i] - v0);
			tf = v[i] - v[i + 1];
			if(t0 + tf <= t[i]){
				d += v0 * t0 + t0 * t0 / 2;
				d += v[i] * (t[i] - t0 - tf);
				d += v[i] * tf - tf * tf / 2;
			}
			else{
				t0 = (v[i + 1] - v0 + t[i]) / 2;
				d += v0 * t0 + t0 * t0 / 2;
				d += (v0 + t0) * (t[i] - t0) - (t[i] - t0) * (t[i] - t0) / 2;
			}
			v0 = v[i + 1];
		}
	}	
	t0 = 0;
	int i = n - 1;
	if(v0 < v[i])
		t0 = min(t[i], v[i] - v0);
	tf = v[i];
	if(t0 + tf <= t[i]){
		d += v0 * t0 + t0 * t0 / 2;
		d += v[i] * (t[i] - t0 - tf);
		d += v[i] * tf - tf * tf / 2;
	}
	else{
		t0 = (- v0 + t[i]) / 2;
		d += v0 * t0 + t0 * t0 / 2;
		d += (v0 + t0) * (t[i] - t0) - (t[i] - t0) * (t[i] - t0) / 2;
	}
	cout << d;
	return 0;
}
