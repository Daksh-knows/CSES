#include<bits/stdc++.h>
using namespace std;

long long n, m, u, v, cost;
vector<vector<long long>> edges;
vector<pair<int,long long>> g[100100], rg[100100];
long long dist[100100];
int reachable[100100];

void findReachable(int src, vector<pair<int,long long>> graph[]){
    queue<int> q; q.push(src);
    vector<bool> vis(n+1, false);
    while(!q.empty()){
        auto t  = q.front(); q.pop();
        if(vis[t]) continue;
        reachable[t]++;
        vis[t] = true;
        for(auto it : graph[t]){
            q.push(it.first);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> u >> v >> cost;
        g[u].push_back({v,cost});
        rg[v].push_back({u,cost});
        edges.push_back({u,v,cost});
    }
    for(int i=1; i<=n; i++) dist[i] = LLONG_MIN, reachable[i] = 0;
    dist[1] = 0;
    findReachable(1, g);
    findReachable(n, rg);
    for(int i=1; i<n; i++){
        for(auto edge : edges){
            if(dist[edge[0]] != LLONG_MIN){
                dist[edge[1]] = max(dist[edge[1]], dist[edge[0]] + edge[2]);
            }
        }
    }
    bool hasCycle = false;
    for(auto edge : edges){
        if(dist[edge[0]] != LLONG_MIN && reachable[edge[1]] == 2){
            hasCycle |= (dist[edge[0]] + edge[2] > dist[edge[1]]);
        }
    }
    if(hasCycle){
        cout << "-1";
    }else{
        cout << dist[n] << '\n';
    }
    return 0;

}