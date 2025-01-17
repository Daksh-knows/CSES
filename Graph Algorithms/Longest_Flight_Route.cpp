#include<bits/stdc++.h>
using namespace std;

int n,m,u,v;
vector<vector<int>> adj;
vector<int> next_node, route;
vector<bool> vis;

int main(){
    cin >> n >> m;
    adj.resize(n+1);
    next_node.resize(n+1, -1);
    route.resize(n+1, -1);
    route[n] = 1;
    vis.resize(n+1, false);
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    function<void(int)> dfs = [&](int src){
        vis[src] = true;
        for(int nxt : adj[src]){
            if(!vis[nxt])
                dfs(nxt);
            if(route[nxt] != -1 && route[src] < route[nxt] + 1){
                route[src] = route[nxt] + 1;
                next_node[src] = nxt;
            }
        }
    };

    dfs(1);
    if(route[1] == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << route[1] << '\n';
    for(int node = 1; node != -1; node = next_node[node]){
        cout << node << ' ';
    }
    return 0;
}