#include <bits/stdc++.h>
using namespace std;
struct a{
    long long s;
    int cnt=1,sz=1,hvy,hsz;
    unordered_map<int,int> mp;
} nd[100010];
bool vis[100010];
vector<int> g[100010];
long long ans[100010];
int dfs1(int u){
    vis[u]=1;
    for(int v:g[u])
        if(!vis[v]){
            int tmp=dfs1(v);
            if(tmp>nd[u].hsz)nd[u].hvy=v,nd[u].hsz=tmp;
            nd[u].sz+=tmp;
        }
    return nd[u].sz;
}
void dfs2(int u){
    vis[u]=1;
    if(g[u].size()==1&&vis[g[u][0]]){
        ans[u]=nd[u].s;
        return;
    }
    int &h=nd[u].hvy;
    if(h){
        dfs2(h);
        for(auto x:nd[h].mp){
            int &tmp=nd[u].mp[x.first];
            tmp+=x.second;
            if(tmp>nd[u].cnt){
                nd[u].cnt=tmp;
                nd[u].s=x.first;
            }
            else if(tmp==nd[u].cnt)nd[u].s+=x.first;
        }
    }
    for(int v:g[u])
        if(!vis[v]){
            dfs2(v);
            for(auto x:nd[v].mp){
                int &tmp=nd[u].mp[x.first];
                tmp+=x.second;
                if(tmp>nd[u].cnt){
                    nd[u].cnt=tmp;
                    nd[u].s=x.first;
                }
                else if(tmp==nd[u].cnt)nd[u].s+=x.first;
            }
        }
    ans[u]=nd[u].s;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int tmp;
        cin>>tmp;
        ++nd[i].mp[tmp];
        nd[i].s=tmp;
    }
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1);
    memset(vis,0,sizeof(vis));
    dfs2(1);
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
    return 0;
}
