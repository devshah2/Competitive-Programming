//http://www.usaco.org/index.php?page=viewproblem2&cpid=1157
//Solved in O(n^2*k), faster than desired O(n^3)
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll t;cin>>t;
    while(t--){
        // cout<<"test"<<endl;
        ll n,k;cin>>n>>k;
        bool hay[n][n];
        for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) hay[i][j]=false;
        char c;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>c;
                if(c=='H') hay[i][j]=true;
            }
            
        }

        // for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cout<<hay[i][j]<<" ";
        // cout<<endl;
        vector<vector<vector<pair<ll,ll> > > > ans; 
        ans.resize(n);
        for(ll i=0;i<n;i++) ans[i].resize(n);
        for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) ans[i][j].resize(4);
        ans[n-1][n-1][0]=make_pair(1,1);
        ans[n-1][n-1][1]=ans[n-1][n-1][2]=ans[n-1][n-1][3]=make_pair(0,0);
        // cout<<"test"<<endl;
        for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) for(ll k=0;k<4;k++) ans[i][j][k]=make_pair(0,0);
        ans[n-1][n-1][0]=make_pair(1,1);
        for(ll i=n-2;i>=0;i--){
            if(!hay[n-1][i] && ans[n-1][i+1][0].first!=0) ans[n-1][i][0]=make_pair(1,0);
            if(!hay[i][n-1] && ans[i+1][n-1][0].second!=0) ans[i][n-1][0]=make_pair(0,1);
            ans[n-1][i][1]=ans[n-1][i][2]=ans[n-1][i][3]=make_pair(0,0);
            ans[i][n-1][1]=ans[i][n-1][2]=ans[i][n-1][3]=make_pair(0,0);
        }
        ans[n-1][n-1][0]=make_pair(1,1);
        // cout<<"test"<<endl;
        for(ll i=n-2;i>=0;i--){
            for(ll j=n-2;j>=0;j--){
                // cout<<i<<" "<<j<<endl;
                ans[i][j][0]=ans[i][j][1]=ans[i][j][2]=ans[i][j][3]=make_pair(0,0);
                // ans[i][j][0].first+=ans[i][j+1][0].first;
                // // cout<<i<<" "<<j<<endl;
                // ans[i][j][0].second+=ans[i+1][j][0].second;
                // // cout<<i<<" "<<j<<endl;
                // ans[i][j][1].first+=ans[i][j+1][1].first;
                // ans[i][j][1].second+=ans[i+1][j][1].second;
                // ans[i][j][2].first+=ans[i][j+1][2].first;
                // ans[i][j][2].second+=ans[i+1][j][2].second;
                // ans[i][j][3].first+=ans[i][j+1][3].first;
                // ans[i][j][3].second+=ans[i+1][j][3].second;
                // cout<<i<<" "<<j<<endl;
                if(!hay[i][j]){
                    for(ll k=0;k<4;k++){ 
                        ans[i][j][k].first+=ans[i][j+1][k].first;
                        ans[i][j][k].second+=ans[i+1][j][k].second;
                        if(k!=3){
                            ans[i][j][k+1].second+=ans[i+1][j][k].first;
                            ans[i][j][k+1].first+=ans[i][j+1][k].second;
                        }
                    }
                }
                // cout<<i<<" "<<j<<endl;
                
            }
        }
        // for(ll i=0;i<n;i++){
        //     for(ll j=0;j<n;j++){
        //         for(ll k=0;k<4;k++){
        //             cout<<ans[i][j][k].first<<" "<<ans[i][j][k].second<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<"test"<<endl;
        ll answer=0;
        answer=ans[0][0][0].first+ans[0][0][0].second;
        if(k>=1){
            answer+=ans[0][0][1].first+ans[0][0][1].second;
        }
        if(k>=2){
            answer+=ans[0][0][2].first+ans[0][0][2].second;
        }
        if(k>=3){
            answer+=ans[0][0][3].first+ans[0][0][3].second;
        }
        cout<<answer<<endl;
    }
    return 0;
}