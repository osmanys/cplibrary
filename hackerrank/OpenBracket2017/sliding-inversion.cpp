#include <bits/stdc++.h>
#define MAX 500000

using namespace std;
long d[MAX], T[MAX];

long getSum(long BITree[], long index){
    long sum = 0;
    while (index > 0){
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void addBIT(long BITree[], long n, long index){
    while (index <= n){
       BITree[index]++;
       index += index & (-index);
    }
}

void removeBIT(long BITree[], long n, long index){
    while (index <= n){
       BITree[index]--;
       index += index & (-index);
    }
}

int main(){
	long n, m, k, u;
	scanf("%ld %ld", &n, &m);
	for(long i = 0; i < n; i++) scanf("%ld", &d[i]);
	memcpy(T, d, sizeof(long) * n);
	sort(T, T + n);
	k = unique(T, T + n) - T;
	for (long i = 0; i < n; i++){
		u = lower_bound(T, T + k, d[i]) - T + 1;
		d[i] = u;
	}
	long BIT[k];
	for(long i = 0; i < k; i++)
		BIT[i] = 0;
	long c = 0;
	for(long i = m - 1; i >= 0; i--){
        c += getSum(BIT, d[i] - 1);
        addBIT(BIT, k, d[i]);
	}
	long long r = c;
	for(long i = m; i < n; i++){
		removeBIT(BIT, k, d[i - m]);
		c -= getSum(BIT, d[i - m] - 1);
		c += m - 1 - getSum(BIT, d[i]);
		addBIT(BIT, k, d[i]);
		r += c;
	}
	cout << r;
	return 0;
}
