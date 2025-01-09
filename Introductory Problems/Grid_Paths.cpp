#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll x, sum = 0, ans = 0; cin >> x;
    cin>>x;
	x=abs(x);
	while (sum<x || (sum-x)%2==1) {sum+= (++ans);}
	cout<<ans;
	return 0;
}