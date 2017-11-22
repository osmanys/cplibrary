#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, k;
	cin >> n >> k;
	printf((n / k) & 1 ? "YES" : "NO");
	return 0;
}
