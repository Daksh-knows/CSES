#include<bits/stdc++.h>
using namespace std;

int n,m,u,v;
vector<vector<int>> adj;
vector<int> degree;
vector<int> path;

int main(){
    cin >> n >> m;
    adj.resize(n+1);
    degree.resize(n+1);
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
    }
    queue<int> q;
    for(int i=1; i<=n; ++i){
        if(degree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int fr = q.front(); q.pop();
        path.push_back(fr);
        for(auto it : adj[fr]){
            if(--degree[it] == 0){
                q.push(it);
            }
        }
    }
    if(path.size() != n)
        cout << "IMPOSSIBLE";
    else
        for(auto it : path) cout << it << ' ';
    return 0;
}