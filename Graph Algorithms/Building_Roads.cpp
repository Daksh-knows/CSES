#include<bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
vector<int> graph[100100];
bool vis[100100];


int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1; i<=n; i++) vis[i] = false;

    function<void(int)> dfs = [&](int src)->void{
        if(vis[src]) return;
        vis[src] = true;
        cnt++;
        for(int next : graph[src]){
            dfs(next);
        }
    };
    dfs(1);
    if(cnt == n){
        cout << "0\n"; return 0;
    }
    vector<vector<int>> res;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            res.push_back({1, i});
            // cout << cnt << ' ';
        }
        if(cnt == n) break;
    }
    cout << res.size() << '\n';
    for(auto it : res) cout << it[0] << ' ' << it[1] << '\n';
    return 0;
}