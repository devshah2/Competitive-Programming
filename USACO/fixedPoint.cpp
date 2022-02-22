#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n,q;cin>>n>>q;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    while(q--){
        ll start,end; cin>>start>>end;
        end=n-end;
        ll ans=0;
        vector<ll> val;
        for(ll i=0;i<n;i++) val.push_back(a[i]);
        ll count=end-1;
        while(count>=start){
            if(val[count]==count+1){
                
                ans+=1;
                end--;
                // cout<<count<<" "<<val[count]<<" "<<ans<<" "<<end<<endl;
                val.erase(val.begin()+count);
                count=end-1;
            }
            else count--;
        }
        cout<<ans<<endl;

    }
    return 0;
}