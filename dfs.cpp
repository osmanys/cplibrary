#include <bits/stdc++.h>
#define SIZE 100000

using namespace std;
map<int, vector<int>> graph;
int n, e;
bool visited[SIZE];

int countdfs(int source){
    visited[source] = true;
    int count = 0;
    for(int i = 0; i < graph[source].size(); i++){
        if(!visited[graph[source][i]]){
            count += countdfs(graph[source][i]);
        }
    }
    return count + 1;
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 
    vector<int> groups = {};
    for(map<int, vector<int>>::iterator it = graph.begin(); it != graph.end(); it++){
        if(!visited[it->first]){
            groups.push_back(countdfs(it->first));
        }
    }
    groups.push_back(n - graph.size());
    long long result = (n - graph.size())*(n - graph.size() - 1)/2;
    for(int i = 0; i < groups.size() - 1; i++)
        for(int j = i + 1; j < groups.size(); j++)
            result += groups[i]*groups[j];
    cout << result << endl;
    return 0;
}
