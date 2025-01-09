#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,q; cin >> n >> q;
    long long pref[n];
    for(int i=0; i<n; i++) cin >> pref[i];
    for(int i=1; i<n; i++) pref[i] ^= pref[i-1];
    while(q--){
        long long l,r; cin >> l >> r; l--, r--;
        long long res = pref[r] ^ ((l > 0)? pref[l-1]:0); 
        cout << res << '\n';
    }   
    return 0;
}