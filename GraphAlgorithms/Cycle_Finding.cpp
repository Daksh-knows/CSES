#include<bits/stdc++.h>
using namespace std;

int n,m,u,v;
const long long INF = 2e18;
vector<vector<long long>> edges;
long long x, dist[100100], relaxant[100100];

int main(){
    cin >> n >> m;
    
    for(int i=0; i<m; ++i){
        cin >> u >> v >> x;
        edges.push_back({u,v,x});
    }   
    for(int i=0; i<=n; i++) relaxant[i] = -1, dist[i] = 0;
    relaxant[0] = 0;

    int varr = -1;
    for(int i=1; i<=n; i++){
        varr = -1;
        for(auto edge : edges){
            u = edge[0], v = edge[1], x = edge[2];
            if(dist[u] + x < dist[v]){
                dist[v] = dist[u] + x;
                relaxant[v] = u; 
                varr = v;
            }
        }
    }
    if(varr == -1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        vector<int> path;
        for(int i=1; i<=n; i++){
            varr = relaxant[varr];
        }
        for(int w = varr; ; w = relaxant[w]){
            path.push_back(w);
            if(w == varr && path.size() > 1){
                break;
            }
        }
        reverse(path.begin(), path.end());
        for(auto it : path) cout << it << ' ';
    }

    return 0;
}