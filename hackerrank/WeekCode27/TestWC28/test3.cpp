#include <bits/stdc++.h>
#define SIZE 100000

using namespace std;
map<long long,vector<long long> > graph;
map<long long,vector<long long> > sets;
bool visited[SIZE];
long long t,n,e,nodes,edges;

void countdfs(int source,long long &nodes,long long &edges){
    visited[source]=true;
    for(int i=0;i<graph[source].size();i++){
        if(!visited[graph[source][i]]){
            countdfs(graph[source][i],nodes,edges);
        }
    }
    nodes++;
    edges+=graph[source].size();
}
int main(){
    //cin>>t;
    t=16;
    while(t--){
        //cin>>n>>e;
        n=100000;
        e=100000;
        graph.clear();
        for (int i=0;i<e;i++){
            int a,b;
            //cin>>a>>b;
            a=rand()%100000+1;
            b=rand()%100000+1;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        memset(visited,0,n*sizeof(bool));
        sets.clear();
        for(map<long long,vector<long long> >::iterator it=graph.begin();it!=graph.end();it++){
            if(!visited[it->first]){
                nodes=0;
                edges=0;
                countdfs(it->first,nodes,edges);
                sets[nodes].push_back(edges/2);
            }
        }
        long long result=0;
        long long ecount=e;
        long long ncount=0;
        for(map<long long,vector<long long> >::reverse_iterator it=sets.rbegin();it!=sets.rend();it++){
            nodes=it->first;
            for(int i=0;i<it->second.size();i++){
                edges=it->second[i];
                result+=nodes*(nodes+1)*(2*nodes+1)/6;
                result-=nodes*(nodes+1)/2;
                result+=ncount*(nodes-1);
                ncount+=nodes*(nodes-1);
                ecount-=nodes-1;
            }
        }
        result+=ncount*ecount;
        cout<<result<<endl;
    }
    return 0;
}

