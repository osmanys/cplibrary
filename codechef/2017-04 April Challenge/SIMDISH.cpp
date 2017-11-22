#include <bits/stdc++.h>
//#define fi "SIMDISH.in"
//#define fo "SIMDISH.out"

using namespace std;

int main(){
    //freopen(fi, "r", stdin);
	//freopen(fo, "w", stdout);    
    // code here
    int t;
    string s1, s2, s3, s4, ss1, ss2, ss3, ss4;
    bool find;
    scanf("%d", &t);
    while(t--){
    	cin >> s1 >> s2 >> s3 >> s4;
    	cin >> ss1 >> ss2 >> ss3 >> ss4;
    	find = false;
    	if(!s1.compare(ss1) || !s1.compare(ss2) || !s1.compare(ss3) || !s1.compare(ss4))
    		find = true;
    	if(!s2.compare(ss1) || !s2.compare(ss2) || !s2.compare(ss3) || !s2.compare(ss4)){
	    	if(find){
	    		printf("similar\n");
	    		continue;
			}
			find = true;
		}
    	if(!s3.compare(ss1) || !s3.compare(ss2) || !s3.compare(ss3) || !s3.compare(ss4)){
	    	if(find){
	    		printf("similar\n");
	    		continue;
			}
			find = true;
		}
    	if(!s4.compare(ss1) || !s4.compare(ss2) || !s4.compare(ss3) || !s4.compare(ss4)){
	    	if(find){
	    		printf("similar\n");
	    		continue;
			}
			find = true;
		}
		printf("dissimilar\n");
	}
    
	return 0;
}
