#include <bits/stdc++.h>
#define MAX 101

using namespace std;
int nim[MAX];

int mex(vector<int> nims){
    sort(nims.begin(),nims.end());
    int s = -1;
    for(vector<int>::iterator i=nims.begin();i!=nims.end();i++){
        if(*i-s>1)
            break;
        s=*i;
    }
    return s+1;
}
int nimber(int n){
    if(n<2)
        return 0;
    if(n<7)
        return 1;
    vector<int> nims={nim[n-5],nim[n-3],nim[n-2]};
    return mex(nims);
}
int main() {
    for(int i=0;i<MAX;i++){
        nim[i]=nimber(i);
        //cout<<i<<" "<<nim[i]<<endl;
    }
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
            cout<<(nim[n]?"First":"Second")<<endl;
    }
    return 0;
}
