#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("1a.in", "r", stdin);
    clock_t exc = clock();
    #endif
    
    // Code here
    int n, m;
	long a;
    scanf("%d %d %ld", &n, &m, &a);
    cout << (long long)(ceil(1.0L * n / a) * ceil(1.0L * m / a));
    
    #ifndef ONLINE_JUDGE
    cout << endl << (double)(clock()-exc)/CLOCKS_PER_SEC*1000 << "ms.\n";
    #endif
	return 0;
}
