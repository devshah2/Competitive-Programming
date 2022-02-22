#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n;cin>>n;
    string s;
    cin>>s;
    // cout<<s<<endl;
    // for(ll i=0;i<n;i++) cout<<s[i]<<" ";
    // cout<<endl;
    bool breed[n];
    for(ll i=0;i<n;i++) breed[i]=(s[i]=='H');
    // for(ll i=0;i<n;i++) cout<<breed[i]<<" ";
    ll ans=0;
    // cout<<"test"<<endl;
    for(ll i=2;i<n;i++){
        ll count=breed[i-1]+breed[i-2];
        ll count2=!breed[i-1]+!breed[i-2];
        for(ll j=i;j<n;j++){
            count+=breed[j];
            count2+=!breed[j];
            
            if(count>1 && count2>1){
                // cout<<count<<" "<<count2<<endl;
                ans+=n-j;
                break;
            }
            else if(count!=1 && count2!=1){
                // cout<<count<<" "<<count2<<endl;
                ans++;
            }
        }
        // cout<<i<<" "<<count<<" "<<count2<<endl;
        // cout<<"test"<<endl;
        // while((count==1 || (j-i+1-count)==1) && j<n-1){
        //     j++;
        //     count+=breed[j];
        // }
        // if(count!=1 && count2!=1) ans+=(n-count-count2-i+3);
    }
    n-=2;
    cout<<(n*(n+1))/2-ans<<endl;
    return 0;
}