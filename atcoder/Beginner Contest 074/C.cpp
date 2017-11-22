#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d, e, f, raa = 0, rbb = 0, rcc = 0, rdd = 0, maxdn = 0, maxdd = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for(long iaa = 0; iaa * a * 100 <= f; iaa++){
		for(long ibb = 0; ibb * b * 100 <= f; ibb++){
			for(long icc = 0; icc * c <= f; icc++){
				for(long idd = 0; idd * d <= f; idd++){
					if(iaa * a * 100 + ibb * b * 100 + icc * c + idd * d <= f){
						if((iaa * a + ibb * b) * e >= (icc * c + idd * d)){
							if((iaa * a + ibb * b) * maxdn <= (icc * c + idd * d) * maxdd){
								maxdn = (icc * c + idd * d);
								maxdd = (iaa * a + ibb * b);
								raa = iaa;
								rbb = ibb;
								rcc = icc;
								rdd = idd;
							}
						}
					}
				}		
			}		
		}		
	}
	cout << (raa * a * 100 + rbb * b * 100 + rcc * c + rdd * d) << " " << (rcc * c + rdd * d);
	return 0;
}
