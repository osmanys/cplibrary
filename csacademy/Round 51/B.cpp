#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int d[MAX];

int main() {
    int n, p;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &p);
        d[i] = (i + p) > n ? n - 1 : (i + p);
    }
    sort(d, d + n);
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(d[cur] != d[i]){
            for(int j = i - 1; j >= cur; j--){
                printf("%d ", j + 1);
            }
            cur = i;
        }
    }
    for(int j = n - 1; j >= cur; j--){
        printf("%d ", j + 1);
    }
    return 0;
}
