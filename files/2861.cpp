#include <bits/stdc++.h>
#define max(a,b) (a<b)?b:a
using namespace std;
vector<pair<int,int>> g[40010];
int sz[40010],n,fz;
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
long long dfs3(int rt){
    vis[rt]=1;
    long long ans=0;
    int tot[3]={1,0,0};
    for(auto v:g[rt])
        if(!vis[v.first]){
            int sub[3];
            dist.clear();
            dfs2(v.first,0,v.second);
            sub[0]=sub[1]=sub[2]=0;
            for(int x:dist)++sub[x%3];
            ans += 1LL*sub[0]*tot[0];
            ans += 1LL*sub[1]*tot[2];
            ans += 1LL*sub[2]*tot[1];
            for(int i=0;i<3;i++)tot[i]+=sub[i];
        }
    for(auto v:g[rt])
        if(!vis[v.first]){
            dfs11(v.first,rt);
            fz=v.first;
            dfs12(v.first,rt,sz[v.first]);
            ans+=dfs3(fz);
        }
    return ans;
}
long long gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}
int main(){
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    fz=1;
    dfs11(1,0);
    dfs12(1,0,sz[1]);
    long long fz2=dfs3(fz)*2+n;
    long long fm=1LL*n*n;
    long long tmp=gcd(fz2,fm);
    cout<<fz2/tmp<<'/'<<fm/tmp;
    return 0;
}
