#include <bits/stdc++.h>
#define MAX_SIZE 100001

using namespace std;
int l[MAX_SIZE];
long long result;
int n, p, current, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> p;
    for(int i = 0; i < n; i++)
        cin >> l[i];
    sort(l, l + n);
    result = 0LL;
    current = 0;
    for(int i = 0; i < n; i++)
    {
        t = l[i] / p + (l[i] % p ? 1 : 0);
        if(current < t)
            current = t;
        else
            current++;
        result += current;
    }
    cout << result << '\n';
    return 0;
}
