#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[1000]={-1};
ll dpF(ll i, vector<ll> entries, map<ll,ll> m, vector<vector<ll> > indexes){
    if(dp[i]!=-1) return dp[i];
    dp[i]=1;
    for(ll j=0;j<i;j++){
        if(entries[j]<entries[i]){
            
        }
    }
}

int main(){
    ll n;cin>>n;
    ll aA[n];
    for(ll i=0;i<n;i++) cin>>aA[i];
    ll m;cin>>m;
    ll bA[m];
    for(ll i=0;i<n;i++) cin>>bA[i];
    vector<ll> a;
    vector<ll> b;
    for(ll i=0;i<n;i++){
        if(find(bA,bA+m,aA[i])) a.push_back(aA[i]);
        if(find(aA,aA+n,bA[i])) b.push_back(bA[i]);
    }
    vector<ll> entries;
    vector<ll> others;
    if(b.size()>a.size()){
        copy(a.begin(),a.end(),others);
        copy(b.begin(),b.end(),entries);
    }
    else{
        copy(a.begin(),a.end(),entries);
        copy(b.begin(),b.end(),others);
    }
    fill(dp,dp+entries.size(),0);
    vector<vector<ll> > indexes;
    map<ll,ll> mapp;
    for(ll i=0;i<others.size();i++){
        auto it=mapp.find(others[i]);
        if(it!=mapp.end()){
            indexes[mapp[others[i]]].push_back(i);
        }
        else{
            mapp.insert(make_pair(others[i],indexes.size()));
            vector<ll> temp;
            temp.push_back(i);
            indexes.push_back(temp);
        }
    }

    return 0;
}