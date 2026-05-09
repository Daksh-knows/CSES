#include<bits/stdc++.h>
using namespace std;

int n,m, par[100100];
bool vis[100100];
vector<int> g[100100];
int sv , ev;
vector<int> path;
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        par[i] = -1, vis[i] = false;
    }
    function<bool(int,int)> dfs = [&](int u, int p){
        vis[u] = true;
        par[u] = p;
        for(auto v : g[u]){
            if(v == p) continue;
            if(vis[v]){
                sv = v;
                ev = u;
                return true;
            }else{
                if(dfs(v, u)){
                    return true;
                }
            }
        }
        return false;
    };
    function<bool()> dfs_all = [&]()->bool{
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                if(dfs(i, -1)){
                    return true;
                }
            }
        }
        return false;
    };
    if(dfs_all()){
        int tv = ev;
        path.push_back(ev);
        while(tv != sv){
            path.push_back(par[tv]);
            tv = par[tv];
        }
        path.push_back(ev);
        cout << path.size() << '\n';
        for(auto it : path) cout << it << ' ';
    }
    else cout << "IMPOSSIBLE";
    return 0;
}