#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    if(n <= 3 && !k){
        cout << -1;
        return 0;
    }
    cout << (2 * n - 2 - k) << "\n";
    for(long i = 1; i < n; i++)
        printf("%ld %ld 1\n", i, i + 1);
    for(long i = 3; i < min(n + 1, n - k + 3); i++)
        printf("1 %ld 2\n", i);
    if(!k)
        printf("2 %ld 2\n", n);
    return 0;
}
