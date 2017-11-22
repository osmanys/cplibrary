#include <bits/stdc++.h>
#define MAX 100000
#define MAX_PIECES (100000 / 64 + 1)

using namespace std;
long long data[26][MAX_PIECES];

long solve(int pos, long long _or[], long mult){
	cout << mult << endl;
	if(pos == 26)
		return LONG_MAX;
	long long _or2[MAX_PIECES];
	bool complete = true;
    for(long i = 0; i < MAX_PIECES; i++){
    	_or2[i] = (_or[i] | data[pos][i]);
    	if(_or2[i] != LLONG_MAX)
    		complete = false;    	
	}
	if(complete)
		return mult + (1L << pos);
	long r1 = solve(pos + 1, _or, mult);
	long r2 = solve(pos + 1, _or2, mult + (1L << pos));
	return min(r1, r2);
}

int main() {
	int n;
	cin >> n;
	long a;
	for(long i = 0; i < n; i++){
		cin >> a;
		for(int j = 0; j < 26; j++)
			data[j][i % 64] += ((a >> j) & 1) << (i % 64);
	}
	for(long i = n; i < MAX; i++)
		for(int j = 0; j < 26; j++)
			data[j][i % 64] += 1 << (i % 64);
	long long _or[MAX_PIECES];
	memset(_or, 0, sizeof _or);
	cout << solve(0, _or, 0) << endl;
	return 0;
}

