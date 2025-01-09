#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q; cin >> n >> q;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    vector<vector<int>> pref(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            pref[i][j] = (grid[i][j] == '*');
            if(j != 0) pref[i][j] += pref[i][j-1] ;
            if(i != 0) pref[i][j] += pref[i-1][j] ;
            if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << pref[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int res = pref[x2][y2] + ((x1 > 0 && y1 > 0)?pref[x1-1][y1-1]:0) - ((x1 > 0)?pref[x1-1][y2]:0) - ((y1 > 0)?pref[x2][y1-1]:0);
        cout << res << '\n'; 
    }
    return 0;
}