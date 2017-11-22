#include <bits/stdc++.h>
#define MAX 500000

using namespace std;
char qop[MAX], rop[MAX];
long qd[MAX], rd[MAX];
int c, rc;

int main(){
	long n, td;
	int d;
	char op, top;
	cin >> n;
	for(long i = 0; i < n; i++){
		cin >> op >> d;
		if(c && op == qop[c - 1]){
			if(op == '&')
				qd[c - 1] &= d;
			else if(op == '|')
				qd[c - 1] |= d;
			else
				qd[c - 1] ^= d;
		}
		else if(c > 1 && op == qop[c - 2] && (op == '^' || qop[c - 1] != '^')){
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
		else if(c > 2 && op == qop[c - 3] && (op == '^' || (qop[c - 1] != '^' && qop[c - 2] != '^'))){
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
	long i = 0;
	for(; i < c && qop[i] != '^'; i++){
		if(rc && qop[i] == rop[rc - 1]){
			if(qop[i] == '&')
				rd[rc - 1] &= qd[i];
			else
				rd[rc - 1] |= qd[i];
		}
		else if(rc > 1 && qop[i] == rop[rc - 2]){
			if(rop[rc - 1] == '&')
				td = rd[rc - 2] & rd[rc - 1];
			else
				td = rd[rc - 2] | rd[rc - 1];
				
			if(rop[rc - 2] == '&')
				td = td & qd[i];
			else
				td = td | qd[i];
			
			top = rop[rc - 2];
			
			rop[rc - 2] = rop[rc - 1];
			rd[rc - 2] = rd[rc - 1];
			
			rop[rc - 1] = top;
			rd[rc - 1] = td;
		}
		else if(rc > 2 && qop[i] == rop[rc - 3]){
			if(rop[rc - 2] == '&')
				td = rd[rc - 3] & rd[rc - 2];
			else
				td = rd[rc - 3] | rd[rc - 2];
			
			if(rop[rc - 1] == '&')
				td = td & rd[rc - 1];
			else
				td = td | rd[rc - 1];				
				
			if(rop[rc - 3] == '&')
				td = td & qd[i];
			else
				td = td | qd[i];				
				
			top = rop[rc - 3];
			
			rop[rc - 3] = rop[rc - 2];
			rd[rc - 3] = rd[rc - 2];
			
			rop[rc - 2] = rop[rc - 1];
			rd[rc - 2] = rd[rc - 1];
			
			rop[rc - 1] = top;
			rd[rc - 1] = td;			
		}
		else{
			rop[rc] = qop[i];
			rd[rc] = qd[i];
			rc++;
		}
	}
	for(; i < c; i++){
		rop[rc] = qop[i];
		rd[rc] = qd[i];
		rc++;
	}
	cout << rc << "\n";
	for(long i = 0; i < rc; i++)
		printf("%c %d\n", rop[i], rd[i]);
	return 0;
}
