#include <bits/stdc++.h>

using namespace std;
char qop[5];
long qd[5];
int c;

int main(){
	long n, td;
	long d;
	char op, top;
	cin >> n;
	for(long i = 0; i < n; i++){
		cin >> op >> d;
		if(c > 0 && op == qop[c - 1]){
			if(op == '&')
				qd[c - 1] &= d;
			else if(op == '|')
				qd[c - 1] |= d;
			else
				qd[c - 1] ^= d;
		}
		else if(c > 1 && op == qop[c - 2]){
			if(qop[c - 1] == '&')
				td = qd[c - 2] & qd[c - 1];
			else if(qop[c - 1] == '|')
				td = qd[c - 2] | qd[c - 1];
			else
				td = qd[c - 2] ^ qd[c - 1];
				
			if(qop[c - 2] == '&')
				td = td & d;
			else if(qop[c - 2] == '|')
				td = td | d;
			else
				td = td ^ d;
			
			top = qop[c - 2];
			
			qop[c - 2] = qop[c - 1];
			qd[c - 2] = qd[c - 1];
			
			qop[c - 1] = top;
			qd[c - 1] = td;
		}
		else if(c > 2 && op == qop[c - 3]){
			if(qop[c - 2] == '&')
				td = qd[c - 3] & qd[c - 2];
			else if(qop[c - 2] == '|')
				td = qd[c - 3] | qd[c - 2];
			else
				td = qd[c - 3] ^ qd[c - 2];
			
			if(qop[c - 1] == '&')
				td = td & qd[c - 1];
			else if(qop[c - 1] == '|')
				td = td | qd[c - 1];
			else
				td = td ^ qd[c - 1];				
				
			if(qop[c - 3] == '&')
				td = td & d;
			else if(qop[c - 3] == '|')
				td = td | d;
			else
				td = td ^ d;				
				
			top = qop[c - 3];
			
			qop[c - 3] = qop[c - 2];
			qd[c - 3] = qd[c - 2];
			
			qop[c - 2] = qop[c - 1];
			qd[c - 2] = qd[c - 1];
			
			qop[c - 1] = top;
			qd[c - 1] = td;			
		}
		else{
			qop[c] = op;
			qd[c] = d;
			c++;
		}
	}
	cout << c << "\n";
	for(long i = 0; i < c; i++)
		printf("%c %d\n", qop[i], qd[i]);
	return 0;
}
