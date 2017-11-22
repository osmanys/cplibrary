#include <bits/stdc++.h>

using namespace std;
vector<long> d;

int main(){
	long n;
	long long k, t;
	cin >> n >> k;
	t = (sqrt(1 + 8 * k) + 1) / 2;
	k -= t * (t - 1) / 2;
	if(t + (k > 0) > n)
		printf("Impossible");
	else{
		string r = "";
		for(long i = 1; i <= t; i++){
			r += "(";
			if(i == k)
				r += "()";
		}
		for(long i = 1; i <= t; i++)
			r += ")";
		for(long i = 0; i < n - t - (k > 0); i++)
			r += "()";
		cout << r;
	}
	return 0;
}
