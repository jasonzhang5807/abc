#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
vector<int> g[maxn];
int n,dfnc,fa[maxn],v[maxn],s[maxn],dep[maxn],top[maxn],hvy[maxn],dfn[maxn],nfd[maxn];
int val[maxn<<2],tag[maxn<<2],ival[maxn];
int p;
void dfs1(int u){
        s[u]=1;
        for(int v:g[u])
                if(v!=fa[u]){
                        fa[v]=u;
                        dep[v]=dep[u]+1;
                        dfs1(v);
                        s[u]+=s[v];
                        if(s[hvy[u]]<s[v])hvy[u]=v;
                }
}
void dfs2(int u){
        dfn[u]=++dfnc;
        nfd[dfnc]=u;
        if(!top[u])top[u]=u;
        if(hvy[u])top[hvy[u]]=top[u],dfs2(hvy[u]);
        for(int v:g[u])
                if(v!=fa[u]&&v!=hvy[u])
                        dfs2(v);
}
inline void pushup(int rt){
        val[rt]=(val[rt<<1]+val[rt<<1|1])%p;
}
inline void pushdown(int rt,int l,int r){
        if(tag[rt]){
                tag[rt<<1]=(tag[rt<<1]+tag[rt])%p;
                tag[rt<<1|1]=(tag[rt<<1|1]+tag[rt])%p;
                int mid=l+r>>1;
                val[rt<<1]=(val[rt<<1]+tag[rt]*(mid-l+1))%p;
                val[rt<<1|1]=(val[rt<<1|1]+tag[rt]*(r-mid))%p;
                tag[rt]=0;
        }
}
void build(int rt,int l,int r){
        if(l==r){
                val[rt]=ival[l];
                return;
        }
        int mid=l+r>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
}
void update(int rt,int l,int r,int ul,int ur,int add){
        if(ul>r||ur<l)return;
        if(ul<=l&&ur>=r){
                val[rt]=(val[rt]+add*(r-l+1))%p;
                tag[rt]=(tag[rt]+add)%p;
                return;
        }
        int mid=l+r>>1;
        pushdown(rt,l,r);
        update(rt<<1,l,mid,ul,ur,add);
        update(rt<<1|1,mid+1,r,ul,ur,add);
        pushup(rt);
}
int query(int rt,int l,int r,int ql,int qr){
        if(ql>r||qr<l)return 0;
        if(ql<=l&&qr>=r)return val[rt];
        int mid=l+r>>1;
        pushdown(rt,l,r);
        return (query(rt<<1,l,mid,ql,qr)+query(rt<<1|1,mid+1,r,ql,qr))%p;
}
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m,r;
        cin>>n>>m>>r>>p;
        for(int i=1;i<=n;++i)cin>>v[i];
        for(int i=1;i<n;++i){
                int u,v;
                cin>>u>>v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        dfs1(r);
        dfs2(r);
        for(int i=1;i<=n;++i)ival[i]=v[nfd[i]];
        build(1,1,n);
        int op,x,y,z,ans;
        while(m--){
                cin>>op;
                if(op==1){
                        cin>>x>>y>>z;
                        z%=p;
                        while(top[x]!=top[y]){
                                if(dep[top[x]]<dep[top[y]])swap(x,y);
                                update(1,1,n,dfn[top[x]],dfn[x],z);
                                x=fa[top[x]];
                        }
                        if(dep[x]>dep[y])swap(x,y);
                        update(1,1,n,dfn[x],dfn[y],z);
                }
                else if(op==2){
                        cin>>x>>y;
                        ans=0;
                        while(top[x]!=top[y]){
                                if(dep[top[x]]<dep[top[y]])swap(x,y);
                                ans=(ans+query(1,1,n,dfn[top[x]],dfn[x]))%p;
                                x=fa[top[x]];
                        }
                        if(dep[x]>dep[y])swap(x,y);
                        cout<<(ans+query(1,1,n,dfn[x],dfn[y]))%p<<'\n';
                }
                else if(op==3){
                        cin>>x>>z;
                        z%=p;
                        update(1,1,n,dfn[x],dfn[x]+s[x]-1,z);
                }
                else{
                        cin>>x;
                        cout<<query(1,1,n,dfn[x],dfn[x]+s[x]-1)<<'\n';
                }
        }
        return 0;
}
