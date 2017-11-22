#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("4a.in", "r", stdin);
    clock_t exc = clock();
    #endif
    
    // Code here
    int n;
    scanf("%d", &n);
    printf("%s", (n == 2 || n&1) ? "NO" : "YES");
    
    #ifndef ONLINE_JUDGE
    cout << endl << (double)(clock()-exc)/CLOCKS_PER_SEC*1000 << "ms.\n";
    #endif
	return 0;
}
