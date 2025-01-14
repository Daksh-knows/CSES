#include<bits/stdc++.h>
using namespace std;

struct pack{
    long long cost;
    int dest;
    bool flag;
    pack(): cost(LLONG_MAX), dest(0), flag(true) {}; 
    pack(long long cost_, int d_, bool flag_): cost(cost_), dest(d_), flag(flag_){};
};

int n,m, u,v;
long long cost;
vector<pair<int, long long>> adj[100100];
long long full[100100], disc[100100];
bool vis[100100][2];

struct Compare{
bool operator()(const pack &p1, const pack &p2){
    return p1.cost > p2.cost;
}
};

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
    }
    for(int i=1; i<=n; i++) full[i] = disc[i] =  LLONG_MAX, vis[i][0] = vis[1][0] = false; 
    priority_queue< pack, vector<pack>, Compare> pq;
    full[1] = disc[1] = 0;
    pq.push(pack(0LL, 1, true));
    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();
        int src = curr.dest;
        bool used = curr.flag;
        // cout << curr.cost << ' ' << curr.dest << ' ' << curr.flag << '\n';
        if(vis[src][used]) continue;
        vis[src][used] = true;
        for(auto it : adj[src]){
            int nxt = it.first;
            long long price = it.second;
            if(used){
                if(disc[nxt] > full[src] + price/2){
                    disc[nxt] = full[src] + price/2;
                    pq.push(pack(disc[nxt], nxt, false));
                }
                if(full[nxt] > full[src] + price){
                    full[nxt] = full[src] + price;
                    // disc[nxt] = min(full[nxt], disc[nxt]);
                    pq.push(pack(full[nxt], nxt, true));
                }
            }else{  
                if(disc[nxt] > disc[src] + price){
                    disc[nxt] = disc[src] + price;
                    pq.push(pack(disc[nxt], nxt, false));
                }
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout << disc[i] << ' ';
    // }
    // cout << '\n';
    // for(int i=1; i<=n; i++){
    //     cout << full[i] << ' ';
    // }
    // cout << '\n';
    cout << min(disc[n], full[n]) << '\n';
    return 0;
}