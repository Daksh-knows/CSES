#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e15;
int n,m,k,u,v,d,cost;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> dist;

int32_t main(){
    cin >> n >> m >> k;
    dist.resize(n+1);
    adj.resize(n+1);
    for(int i=0; i<=n; i++){
        dist[i].resize(k);
        for(int j=0; j<k; j++){
            dist[i][j] = INF;
        }
    }
    
    
    for(int i=0; i<m; ++i){
        cin >> u >> v >> cost;
        adj[u].push_back({v,cost});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,1});

    while(!pq.empty()){
        u = pq.top().second;
        cost = pq.top().first;
        pq.pop();

        if(dist[u][k-1] < cost) continue;
        // cout << u << ' ' << cost << '\n';   

        for(auto it : adj[u]){
            v = it.first;
            d = it.second;
            if(dist[v][k-1] > cost + d){
                dist[v][k-1] = cost + d;
                pq.push({dist[v][k-1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
    for(int i=0; i<k; i++) cout << dist[n][i] << ' ';
    return 0;
}