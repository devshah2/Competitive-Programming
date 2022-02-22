#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n,m;cin>>n>>m;
    ll k[m];
    for(ll i=0;i<m;i++) cin>>k[i];
    sort(k,k+m);
    ll count=0;
    while(n>=k[count]){
        n-=k[count];
        count++;
    }
    cout<<count<<endl;
    return 0;
}