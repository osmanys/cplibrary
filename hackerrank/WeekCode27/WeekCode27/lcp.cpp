#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

namespace suffix_array{
    #define MAX_N 100001
    char STR[MAX_N];
    int n;
    int RA[MAX_N], tRA[MAX_N];
    int SA[MAX_N], tSA[MAX_N];
    int LCP[MAX_N];
    int c[MAX_N];

    void countSort(int k) {
      int i, sum;
      memset(c, 0, sizeof c);
      for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
      for (i = sum = 0; i < 3000; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
      }
      for (i = 0; i < n; i++)
        tSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
      for (i = 0; i < n; i++)
        SA[i] = tSA[i];
    }

    void buildSA(){
        int i, k, r;
        for (i = 0; i < n; i++)
            RA[i] = STR[i];
        for (i = 0; i < n; i++)
            SA[i] = i;
        for (k = 1; k < n; k <<= 1) {
            countSort(k);
            countSort(0);
            tRA[SA[0]] = r = 0;
            for (i = 1; i < n; i++)
                tRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
            for (i = 0; i < n; i++)
                RA[i] = tRA[i];
            if (RA[SA[n-1]] == n-1)
                break;
        }
    }

    void buildLCP(){
        for(int i = 0, k = 0; i < n; ++i, k ? --k : 0){
            if(RA[i] == n - 1){
                k = 0;
                continue;
            }
            int j = SA[RA[i]+1];
            while(i + k < n && j + k < n && STR[i + k] == STR[j + k])
                ++k;
            LCP[RA[i]] = k;
        }
    }
}

using namespace suffix_array;

lli how_many(int n){
    int x = n - SA[0];
    lli ans = x ;
    for(int i = 0 ; i < n - 1; ++i){
        x = n - (SA[i+1] + LCP[i]);
        ans += x;
    }
    return ans;
}

int main(){
    int n, q;
    cin >> n >> q;
    char *str = new char[n + 1]();

    cin >> str;
    int a, b;
    while(q--){
        cin >> a >> b;
        if(a == b){
            cout << 1 << '\n';
            continue;
        }
        char ch = str[b + 1];
        str[b + 1] = 0;
        strcpy(STR, str + a);
        str[b + 1] = ch;

        suffix_array :: n = b - a + 1;

        buildSA();
        buildLCP();
        cout << how_many(b - a + 1) << '\n';
    }
    return 0;
}
