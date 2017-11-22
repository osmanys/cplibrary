#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;


long long normal(int n, string number){
    vector<string> mult3;
    for(int i=0;i<10;i++)
        if(!(i%8)){
            mult3.push_back(string(2,'0').append(std::to_string(i)));
        }
    for(int i=10;i<100;i++)
        if(!(i%8)){
            mult3.push_back(string(1,'0').append(to_string(i)));
        }
    for(int i=100;i<1000;i++)
        if(!(i%8)){
            mult3.push_back(std::to_string(i));
        }
    vector<string> mult12;
    for(int i=0;i<10;i++)
        if(!(i%8)){
            mult12.push_back(string(1,'0').append(std::to_string(i)));
        }
    for(int i=10;i<100;i++)
        if(!(i%8)){
            mult12.push_back(std::to_string(i));
        }
    for(int i=0;i<10;i++)
        if(!(i%8)){
            mult12.push_back(std::to_string(i));
        }
    long long result=0;
    for(string mult:mult12){
        int m=mult.length();
        long long c[m+1][n+1];
        for (int j=0;j<=m;j++)
            c[j][0]=0;
        for (int j=0;j<=n;j++)
            c[0][j]=1;
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++)
            {
                if (mult[m-i]!=number[n-j])
                    c[i][j]=c[i][j-1];
                else
                    c[i][j]=c[i][j-1]+c[i-1][j-1];
            }
        }
        result=fmod(result+c[m][n],MOD);
    }
    for(string mult:mult3){
        int m=mult.length();
        long long c[m+1][n+1];
        for (int j=0;j<=m;j++)
            c[j][0]=0;
        for (int j=0;j<=n;j++)
            c[0][j]=1;
        for (int i=1;i<m;i++){
            for (int j=1;j<n;j++)
            {
                if (mult[m-i]!=number[n-j])
                    c[i][j]=c[i][j-1];
                else
                    c[i][j]=fmod(c[i][j-1]+c[i-1][j-1],MOD);
            }
        }
        for (int j=1;j<=n;j++)
        {
            if (mult[0]!=number[n-j])
                c[m][j]=fmod(2*c[m][j-1],MOD);
            else
                c[m][j]=fmod(2*c[m][j-1]+c[m-1][j-1],MOD);
        }
        result=fmod(result+c[m][n],MOD);
    }
    return result;
}
long long calcbf(int n,string number,vector<int> s){
    return 0;
}
long long bf(int n,string number){
    vector<int> s={};
    return calcbf(n,number,s);
}

int main(){
    int n=5;
    string number="";
    for(int i=0;i<n;i++)
        number+=std::to_string(rand()%5);
    cout<<normal(n,number)<<endl;
    cout<<bf(n,number)<<endl;
    return 0;
}
