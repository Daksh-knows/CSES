#include<bits/stdc++.h>
using namespace std;

void dfs(vector<string>& grid, int r, int c){
    if(r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == '.'){
        grid[r][c] = '#';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
}

int main(){
    int n,m, ans=0; cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.'){
                ans++;
                dfs(grid, i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}