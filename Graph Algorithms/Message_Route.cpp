#include<bits/stdc++.h>
using namespace std;

int n,m; 
vector<int> graph[100100];
bool vis[100100];
int par[100100];
vector<int> path;

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++) vis[i] = false, par[i] = -1;

    queue<int> q;
    par[1] = 0, vis[1] = true;
    q.push(1);
    while(!q.empty()){
        int nxt = q.front(); q.pop();
        if(nxt == n){
            path.push_back(nxt);
            while(par[nxt] != 0){
                path.push_back(par[nxt]);
                nxt = par[nxt];
            }
            break;
        }
        for(int to : graph[nxt]){
            if(!vis[to]){
                par[to] = nxt, vis[to] = true;
                q.push(to);
            }
        }
    }
    if(path.empty()){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << path.size() << '\n';
        while(!path.empty()){
            cout << path.back() << ' ';
            path.pop_back();
        }
    }
    return 0;
}