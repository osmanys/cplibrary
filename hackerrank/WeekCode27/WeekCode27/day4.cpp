#include <bits/stdc++.h>

using namespace std;
int g, n, i;
long long int p;
long long int s;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> g;
    while(g--){
        cin >> n;
        s = 0;
        for(i = 0; i < n; i++){
            cin >> p;
            s ^= (p % 2 ? p + 1 : p - 1);
        }
        cout << (s ? "W" : "L") << '\n';
    }
    return 0;
}
