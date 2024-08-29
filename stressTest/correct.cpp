#include <bits/stdc++.h>
using namespace std;

#define ll long long


vector<int> ans;

void dfs(vector<vector<ll>> &v,ll curr, vector<ll> &v1)
{
    if(v[curr].size()>0) dfs(v,v[curr][0],v1);
    ans.push_back(v1[curr]);
    if(v[curr].size()>1) dfs(v,v[curr][1],v1);

}
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll x,y;
    cin>>x>>y;
    vector<vector<ll>> g(n);
    for(int i=0;i<x;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int hehe;
    cin>>hehe;
    dfs(g,0,v);
    cout<<ans[hehe-1]<<endl;
}

