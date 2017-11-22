#include <iostream>

using namespace std;
long long totest(long long x){
    long long p=0;
    long long r=0;
    while(x>>p){
        if(!((x>>p)&1))
            r+=((long long)1<<p);
        p++;
    }
    return r;
}
long long bruteforce(long long x){
    long long c=0;
    for(long long a=1;a<x;a++){
        if((a^x)>x)
            c++;
        if(!(a%10000000))
            cout<<a<<" "<<c<<" analized!!"<<endl;
    }
    return c;
}
int main()
{
    long long t,b;
    long long maxi=10000000000;
    for(long long i=maxi;i<=maxi;i++){
        t=totest(i);
        b=bruteforce(i);
        if(t!=b)
            cout<<i<<" error "<<t<<" "<<b<<endl;
        if(!(i%100000))
            cout<<i<<" analized!!"<<endl;
    }
    cout << "Hello world!" << endl;
    cin>>t;
    return 0;
}
