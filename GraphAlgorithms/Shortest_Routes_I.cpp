#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, m;
long long dist[100100];
vector<pair<int,long long>> g[100100];
bool vis[100100];


int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u,v,cost; cin >> u >> v >> cost;
        g[u].push_back({v,cost});
    }
    for(int i=1; i<=n; i++){
        dist[i] = INF; vis[i] = false;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.push({0LL, 1});
    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        long long curr_dis = top.first;
        int curr = top.second;
        if(vis[curr]) continue;
        vis[curr] = true;
        for(auto next : g[curr]){
            int nxt = next.first;
            long long cost = next.second;
            if(!vis[nxt] && dist[nxt] > dist[curr] + cost){
                dist[nxt] = dist[curr] + cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << dist[i] << ' ';
    }
    return 0;
}