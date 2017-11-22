#include <bits/stdc++.h>
#define fi "A-large-practice.in"
#define fo "A-large-practice.out"
#define MAX 1000

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, max, p, cur;
    string word, result;
    bool pos[MAX];
    scanf("%d\n", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		getline(cin, word);
		memset(pos, false, sizeof pos);
		cur = word.size();
		while(cur > 1){
			max = 64;
			p = -1;
			for(int j = 0; j < cur; j++){
				if(word[j] >= max){
					max = word[j];
					p = j;
				}
			}
			pos[p] = true;
			cur = p;
		}		
		cur = word.size();
		result = "";
		for(int i = cur - 1; i >= 0; i--){
			if(pos[i])
				result += word[i];
		}
		for(int i = 0; i < cur; i++){
			if(!pos[i])
				result += word[i];
		}
		printf("%s\n", result.c_str());
	}
    
	return 0;
}
