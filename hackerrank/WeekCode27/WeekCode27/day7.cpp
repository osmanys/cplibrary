#include <bits/stdc++.h>

using namespace std;
int n, q, i, j, k, l, r;
string s;
long long int c;
vector<int> v;

int main()
{
    cin >> n >> q >> s;
    while(q--){
        cin >> l >> r;
        c = 0;
        for(i = 1; i < r - l + 2; i++){
            v = {};
            for(j = l; j < r - i + 2; j++){
                for(k = 0; k < v.size(); k++){
                    if(!s.compare(v[k], i, s, j, i))
                        break;
                }
                if(k == v.size())
                    v.push_back(j);
            }
            c += v.size();
        }
        cout << c << '\n';
    }
}
