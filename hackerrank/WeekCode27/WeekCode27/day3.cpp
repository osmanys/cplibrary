#include <bits/stdc++.h>

using namespace std;
int result[2];
int n, q, a;
bool c, c90, c180, c270;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 1; i <= n / 2 + n % 2; i++){
        for(int j = 1; j <= n / 2; j++){
            c = ((i % 7) * (i % 7) * (j % 7) * (j % 7) ) % 7 > 1 && ((i % 7) * (i % 7) * (j % 7) * (j % 7)) % 7 < 6;
            c90 = ((j % 7) * (j % 7) * ((n + 1 - i) % 7) * ((n + 1 - i) % 7)) % 7 > 1 && ((j % 7) * (j % 7) * ((n + 1 - i) % 7) * ((n + 1 - i) % 7)) % 7 < 6;
            c180 = (((n + 1 - i) % 7) * ((n + 1 - i) % 7) * ((n + 1 - j) % 7) * ((n + 1 - j) % 7)) % 7 > 1 && (((n + 1 - i) % 7) * ((n + 1 - i) % 7) * ((n + 1 - j) % 7) * ((n + 1 - j) % 7)) % 7 < 6;
            c270 = (((n + 1 - j) % 7) * ((n + 1 - j) % 7) * (i % 7) * (i % 7)) % 7 > 1 && (((n + 1 - j) % 7) * ((n + 1 - j) % 7) * (i % 7) * (i % 7)) % 7 < 6;

            result[0] += (c == c180)?0:2;
            result[0] += (c90 == c270)?0:2;

            result[1] += (c == c90)?0:1;
            result[1] += (c90 == c180)?0:1;
            result[1] += (c180 == c270)?0:1;
            result[1] += (c270 == c)?0:1;
        }
    }
    while(q > 0){
        cin >> a;
        cout << ((a % 360)?result[(a % 180) / 90]:0) << '\n';
        q--;
    }
    return 0;
}

