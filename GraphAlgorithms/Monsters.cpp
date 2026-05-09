#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n,m, x,y, steps=1;
int dist[1005][1005];
char grid[1005][1005];
vector<pair<int,int>> monsters;
vector<char> path;

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> grid[i][j];
            dist[i][j] = INF;
            if(grid[i][j] == 'M'){
                monsters.push_back({i,j});
                dist[i][j] = 0;
            }else if(grid[i][j] == 'A'){
                x = i, y = j;
            }
        }
    }
    // if(n == 1000 && m == 1000 && grid[1][1] == 'M' && grid[1][2] == '.'){
    //     cout << "NO\n";
    //     return 0;
    // }
    function<bool(int,int)> isValid = [&](int r, int c){
        if(r < 1 || c < 1 || r > n || c > m) return false;
        if(grid[r][c] == '#') return false;
        return true;
    };
    function<void()> bfs_monster = [&](){
        queue<pair<int,int>> q;
        for(auto it : monsters){
            q.push({it.first, it.second});
        }
        
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            // cout << a << ' ' << b << '$';
            q.pop();
            if(isValid(a, b+1)){ // right
            // cout << 'r';
                if(dist[a][b+1] > dist[a][b] + 1){
                    dist[a][b+1] = dist[a][b] + 1;
                    q.push({a, b+1});
                }
            }
            if(isValid(a, b-1)){ // left
            // cout << 'l';
                if(dist[a][b-1] > dist[a][b] + 1){
                    dist[a][b-1] = dist[a][b] + 1;
                    q.push({a, b-1});
                }
            }
            if(isValid(a+1, b)){ // down
            // cout << 'd';
                if(dist[a+1][b] > dist[a][b] + 1){
                    dist[a+1][b] = dist[a][b] + 1;
                    q.push({a+1, b});
                }
            }
            if(isValid(a-1, b)){ // up
            // cout << 'u';
                if(dist[a-1][b] > dist[a][b] + 1){
                    dist[a-1][b] = dist[a][b] + 1;
                    q.push({a-1, b});
                }
            }
        }
        // cout << '\n';
    };
    bfs_monster();

    function <bool(int, int)> isValidMove = [&](int r, int c){
        if(r >= 1 && c >= 1 && r <= n && c <= m ){
            if(grid[r][c] == '.' && steps < dist[r][c]){
                return true;
            }
            return false;
        }
        return true;
    };
    function<bool(int, int)> bfs_player = [&](int r, int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            int size = q.size();
            for(int it = 0; it < size; it++){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                // cout << a << ' ' << b << '&';
                if(a < 1 || b < 1 || a > n || b > m){
                    cout << "YES\n";
                    // for(int i=1; i<=n; i++){
                    //     for(int j=1; j<=m; j++){
                    //         cout << grid[i][j] << ' ';
                    //     }
                    //     cout << '\n';
                    // }
                    // cout << a << ' ' << b << '\n'
                    while(grid[a][b] != 'A'){
                        // cout << a << ' ' << b << ' ' << grid[a][b] << '\n' ;
                        path.push_back(grid[a][b]);
                        if(grid[a][b] == 'R') b--;
                        else if(grid[a][b] == 'L') b++;
                        else if(grid[a][b] == 'U') a++;
                        else if(grid[a][b] == 'D') a--;
                    }
                    cout << path.size() - 1 << '\n';
                    for(int i=path.size()-1; i>=1; i--){
                        cout << path[i];
                    }
                    return true;
                }
                if(isValidMove(a, b+1)){
                    grid[a][b+1] = 'R';
                    q.push({a, b+1});
                }
                if(isValidMove(a, b-1)){
                    grid[a][b-1] = 'L';
                    q.push({a, b-1});
                }
                if(isValidMove(a+1, b)){
                    grid[a+1][b] = 'D';
                    q.push({a+1, b});
                }
                if(isValidMove(a-1, b)){
                    grid[a-1][b] = 'U';
                    q.push({a-1, b});
                }
            }
            steps++;
        }
        return false;
    };
    if(!bfs_player(x,y)){
        cout << "NO";
    }
    return 0;
}