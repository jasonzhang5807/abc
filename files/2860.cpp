#include <bits/stdc++.h>
#define max(a,b) (a<b)?b:a
using namespace std;
vector<pair<int,int>> g[40010];
int sz[40010],n,k,fz;
vector<int> dist;
bool vis[40010];
void dfs11(int u,int fa){
    sz[u]=1;
    for(auto v:g[u])
        if(v.first!=fa&&!vis[v.first]){
            dfs11(v.first,u);
            sz[u]+=sz[v.first];
        }
}
void dfs12(int u,int fa,int tot){
    int mx=0;
    for(auto v:g[u])
        if(v.first!=fa&&!vis[v.first]){
            dfs12(v.first,u,tot);
            mx=max(mx,sz[v.first]);
        }
    mx=max(mx,tot-sz[u]);
    if(mx<=(tot>>1))fz=u;
}
void dfs2(int u,int fa,int dis){
    dist.push_back(dis);
    for(auto v:g[u])
        if(!vis[v.first]&&v.first!=fa)
            dfs2(v.first,u,dis+v.second);
}
inline long long calc(int rt,int dis){
    long long ret=0;
    dist.clear();
    dfs2(rt,0,dis);
    sort(dist.begin(),dist.end());
    int l=0,r=dist.size()-1;
    while(l<r){
        if(dist[l]+dist[r]<=k)ret+=r-l,++l;
        else --r;
    }
    return ret;
}
long long dfs3(int rt){
    vis[rt]=1;
    int ans=calc(rt,0);
    for(auto v:g[rt])
        if(!vis[v.first]){
            fz=v.first;
            dfs11(v.first,rt);
            dfs12(v.first,rt,sz[v.first]);
            ans-=calc(v.first,v.second);
            ans+=dfs3(fz);
        }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin>>k;
    fz=1;
    dfs11(1,0);
    dfs12(1,0,sz[1]);
    cout<<dfs3(fz);
    return 0;
}
