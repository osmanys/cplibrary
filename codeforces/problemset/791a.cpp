#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("791a.in", "r", stdin);
    clock_t exc = clock();
    #endif
    
    // Code here
    int a, b;
    scanf("%d %d", &a, &b);
    cout << floor(log2(1.0f * b / a) / log2(1.5f)) + 1;
    
    #ifndef ONLINE_JUDGE
    cout << endl << (double)(clock()-exc)/CLOCKS_PER_SEC*1000 << "ms.\n";
    #endif
	return 0;
}
