#include <bits/stdc++.h>
#define MAX_SIZE 2001

using namespace std;

int result[4];
bool m[MAX_SIZE][MAX_SIZE];
bool r[MAX_SIZE][MAX_SIZE];
bool t[MAX_SIZE][MAX_SIZE];
int n, q, i, j, k, a;

int main() {
    cin >> n >> q;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            m[i][j] = r[i][j] = (((i % 7) * (i % 7) * (j % 7) * (j % 7) - 1) % 7 > 0 && ((i % 7) * (i % 7) * (j % 7) * (j % 7) - 1) % 7 < 5);
        }
    }
    result[0] = 0;
    for(k = 1; k < 3; k++){
        for(j = 1; j <= n; j++)
            for(i = n; i; i--)
                t[j][n-i+1] = r[i][j];

        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                r[i][j] = t[i][j];

        result[k] = 0;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(r[i][j] != m[i][j])
                    result[k]++;
    }
    result[3] = result[1];

    while(q){
        cin >> a;
        cout << result[(a % 360) / 90] << '\n';
        q--;
    }
    return 0;
}
