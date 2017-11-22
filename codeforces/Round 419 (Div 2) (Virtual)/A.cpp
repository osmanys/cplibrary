#include <bits/stdc++.h>

using namespace std;

int main(){
	int hh, mm, count = 0;
	scanf("%d:%d", &hh, &mm);
	while(10*(hh%10)+hh/10!=mm){
		count++;
		mm++;
		if(mm==60){
			mm = 0;
			hh = (hh+1)%24;
		}
	}
	printf("%d", count);
	return 0;
}
