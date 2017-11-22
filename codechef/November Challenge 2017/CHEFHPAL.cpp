#include <bits/stdc++.h>
 
using namespace std;

int main() {
	long t, n;
	int a;
	char *str;
	cin >> t;
	while(t--){
		scanf("%ld %d", &n, &a);
		if(a > 2){
			cout << "1 ";
			for(long i = 0; i < n; i++)
				cout << ((char)('a' + i % a));
		}
		else if(a == 2){
			if(n < 9){
				int *c = new int[8] { 1, 1, 2, 2, 3, 3, 3, 3 };
				string *s = new string[8] {"a", "ab", "aab", "aabb", "aaaba", "aaabab", "aaababb", "aaababbb"};
				cout << c[n - 1] << " " << s[n - 1];
			}
			else{
				cout << 4 << " ";
				str = new char[n];
				str[0] = 'a';str[1] = 'a';str[2] = 'a';str[3] = 'a';str[4] = 'b';str[5] = 'a';str[6] = 'b';str[7] = 'b';
				for(long i = 8; i < n; i++){
					if((i - 8) % 6 < 4)
						str[i] = 'a';
					else if((i - 8) % 6 == 4){
						str[i] = 'b';
						str[i - 2] = 'b';
					}
					else
						str[i] = 'b';
				}
				for(long i = 0; i < n; i++)
					cout << str[i];
			}
		}
		else{
			cout << n << " ";
			for(long i = 0; i < n; i++)
				cout << 'a';			
		}
		cout << "\n";
	}
    return 0;
}
