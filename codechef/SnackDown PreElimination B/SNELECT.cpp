#include <bits/stdc++.h>
#define MAX 100

using namespace std;
bool eated[MAX];

int main(){
	int t, m, s, n;
	string l;
	cin >> t;
	while(t--){
		cin >> l;
		memset(eated, false, sizeof eated);
		n = l.size();
		for(int i = 0; i < n; i++){
			if(l[i] == 'm'){
				if(i > 0 && l[i - 1] == 's' && !eated[i - 1])
					eated[i - 1] = true;
				else if(i < n - 1 && l[i + 1] == 's' && !eated[i + 1])
					eated[i + 1] = true;
			}
		}
		m = 0;
		s = 0;
		for(int i = 0; i < n; i++){
			if(l[i] == 'm')
				m++;
			else if(l[i] == 's' && !eated[i])
				s++;
		}
		if(m > s)
			cout << "mongooses" << endl;
		else if(m < s)
			cout << "snakes" << endl;
		else
			cout << "tie" << endl;
	}
	
	return 0;
}
