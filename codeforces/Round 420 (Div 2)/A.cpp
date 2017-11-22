#include <bits/stdc++.h>

using namespace std;
long data[50][50];

int main(){
	int n; bool found;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%ld", &data[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(data[i][j] > 1){
				found = false;
				for(int k = 0; !found && k < n; k++){
					for(int l = 0; !found && l < n; l++){
						if(data[i][j] == data[i][k] + data[l][j])
							found = true;
					}
				}
				if(!found){
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes");
	return 0;
}
