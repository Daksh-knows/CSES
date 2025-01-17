#include<bits/stdc++.h>
using namespace std;

int n,m,u,v;
vector<vector<int>> adj;
vector<bool> vis, present;
vector<int> cycle;
stack<int> rec;

int main(){
    cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1, false);
    present.resize(n+1, false);
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    

    function<bool(int)> dfs = [&](int src){
        vis[src] = true;
        present[src] = true;
        rec.push(src);
        for(auto it : adj[src]){
            if(!vis[it]){
                if(dfs(it)) return true;
            }
            if(present[it]){
                rec.push(it);
                return true;
            }
        }   
        present[src] = false;
        rec.pop();
        return false;
    } ;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i)) break;
        }
    }
    if(rec.empty()){
        cout << "IMPOSSIBLE";
        return 0;
    }
    int fin = rec.top(); rec.pop();
    cycle.push_back(fin);
    while(!rec.empty()){
        cycle.push_back(rec.top()); rec.pop();
        if(cycle.back() == fin) break;
    }
    cout << cycle.size() << '\n';
    while(cycle.size()){
        cout << cycle.back() << ' ';
        cycle.pop_back();
    }
    return 0;
}