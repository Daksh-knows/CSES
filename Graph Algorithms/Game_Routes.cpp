#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
vector<int> dp; vector<bool> vis;
vector<vector<int>> adj;
int n,m,u,v;

int32_t main(){
    cin >> n >> m;
    adj.resize(n+1);
    dp.resize(n+1); dp[n] = 1;
    vis.resize(n+1, false);

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    function<void(int)> dfs = [&](int src){
        vis[src] = true;
        for(int nxt : adj[src]){
            if(!vis[nxt]) dfs(nxt);

            dp[src] = (dp[src] + dp[nxt])%mod;
        }
    };
    dfs(1LL);
    cout << dp[1] << '\n';

    return 0;
}