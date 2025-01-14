#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18; 
int n,m,q,u,v; 
long long cost;
long long graph[505][505];
// long long dist[505];
int main(){
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) 
            graph[i][j] = (i == j)? 0LL: INF; 
    
    for(int i=0; i<m; i++){
        cin >> u >> v >> cost;
        graph[u][v] = graph[v][u] = min(graph[u][v], cost);
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j || i == k || j == k) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    while(q--){
        cin >> u >> v;
        if(graph[u][v] != INF)
            cout << graph[u][v] << '\n';
        else 
            cout << "-1\n";
    }
    return 0;
}