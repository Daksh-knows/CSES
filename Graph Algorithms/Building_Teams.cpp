#include<bits/stdc++.h>
using namespace std;

int n, m; 
vector<int> graph[100100];
int color[100100];
bool vis[100100];

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        vis[i] = false, color[i] = -1;
    }
    bool flag = false;
    function<void(int, int)> dfs = [&](int src, int par){
        if(vis[src]){
            if(color[src] == color[par]){
                flag = true;
            }
            return;
        }
        vis[src] = true;
        color[src] = 1 - color[par];
        for(auto it : graph[src]){
            dfs(it, src);
        }
    };
    color[0] = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    if(flag){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(color[i] == 0) cout << "2 ";
        else cout << "1 ";
    }
    return 0;
}