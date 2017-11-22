#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int p;
    cin >> p;
    cout<<((p/2<n/2-p/2)?(p/2):(n/2-p/2))<<endl;
    return 0;
}
