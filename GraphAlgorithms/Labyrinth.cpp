#include<bits/stdc++.h>
using namespace std;

char gr[1001][1001], tr[1001][1001];
int n,m;
bool vis[1001][1001];
vector<char> path;

bool isValid(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m) return false;
    if(gr[x][y] == '#' || vis[x][y]) return false;
    return true;
}

bool bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = true;
    int zz= 0;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        // cout << a << ' ' << b << ' ' << tr[a][b] << '\n';
        q.pop();
        if(gr[a][b] == 'B'){
            while(1){
                path.push_back(tr[a][b]);
                if(path.back() == 'L') b++;
                if(path.back() == 'R') b--;
                if(path.back() == 'U') a++;
                if(path.back() == 'D') a--;
                if(a == x && b == y) break;
            }
            return true;
        }

        if(isValid(a, b-1)) tr[a][b-1] = 'L', q.push({a, b-1}), vis[a][b-1] = true;
        if(isValid(a, b+1)) tr[a][b+1] = 'R', q.push({a, b+1}), vis[a][b+1] = true;
        if(isValid(a+1, b)) tr[a+1][b] = 'D', q.push({a+1, b}), vis[a+1][b] = true;
        if(isValid(a-1, b)) tr[a-1][b] = 'U', q.push({a-1, b}), vis[a-1][b] = true;
        // zz++;
        // if(zz >= ) return false;
    }
    return false;
}

int main(){
    cin >> n >> m;
    int x,y;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> gr[i][j];
            vis[i][j] = false;
            if(gr[i][j] == 'A') x = i, y = j;
        }
    }
    if(bfs(x,y)){
        cout << "YES\n" << path.size() << '\n';
        n = path.size();
        for(int i=n-1; i>=0; i--) cout << path[i];
    }else{
        cout << "NO\n";
    }
    return 0;
}
