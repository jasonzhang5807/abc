#include <bits/stdc++.h>
#define maxn 30010
using namespace std;
vector<int> g[maxn];
int n,dfnc,fa[maxn],v[maxn],s[maxn],dep[maxn],top[maxn],hvy[maxn],dfn[maxn],nfd[maxn];
int val[maxn<<2],mval[maxn<<2],ival[maxn];
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
        val[rt]=val[rt<<1]+val[rt<<1|1];
                mval[rt]=max(mval[rt<<1],mval[rt<<1|1]);
}
void build(int rt,int l,int r){
        if(l==r){
                mval[rt]=val[rt]=ival[l];
                return;
        }
        int mid=l+r>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
}
void update(int rt,int l,int r,int u,int x){
                if(l==r){
                        mval[rt]=val[rt]=x;
                        return;
                }
        int mid=l+r>>1;
                if(u<=mid)update(rt<<1,l,mid,u,x);
                else update(rt<<1|1,mid+1,r,u,x);
        pushup(rt);
}
int query(int rt,int l,int r,int ql,int qr){
        if(ql>r||qr<l)return 0;
        if(ql<=l&&qr>=r)return val[rt];
        int mid=l+r>>1;
        return query(rt<<1,l,mid,ql,qr)+query(rt<<1|1,mid+1,r,ql,qr);
}
int querym(int rt,int l,int r,int ql,int qr){
        if(ql>r||qr<l)return 0xa0a0a0a0;
        if(ql<=l&&qr>=r)return mval[rt];
        int mid=l+r>>1;
        return max(querym(rt<<1,l,mid,ql,qr),querym(rt<<1|1,mid+1,r,ql,qr));
}
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int q;
        cin>>n;
        for(int i=1;i<n;++i){
                int u,v;
                cin>>u>>v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
            for(int i=1;i<=n;++i)cin>>v[i];
        dfs1(1);
        dfs2(1);
        for(int i=1;i<=n;++i)ival[i]=v[nfd[i]];
        build(1,1,n);
                cin>>q;
        string op;
                int u,v,ans;
        while(q--){
                cin>>op>>u>>v;
                if(op=="CHANGE")
                        update(1,1,n,dfn[u],v);
                else if(op=="QMAX"){
                        ans=0xa0a0a0a0;
                        while(top[u]!=top[v]){
                                if(dep[top[u]]<dep[top[v]])swap(u,v);
                                ans=max(ans,querym(1,1,n,dfn[top[u]],dfn[u]));
                                u=fa[top[u]];
                        }
                        if(dep[u]>dep[v])swap(u,v);
                        cout<<max(ans,querym(1,1,n,dfn[u],dfn[v]))<<'\n';
                }
                else{
                        ans=0;
                                                while(top[u]!=top[v]){
                                                        if(dep[top[u]]<dep[top[v]])swap(u,v);
                                                        ans+=query(1,1,n,dfn[top[u]],dfn[u]);
                                                        u=fa[top[u]];
                                                }
                                                if(dep[u]>dep[v])swap(u,v);
                                                cout<<ans+query(1,1,n,dfn[u],dfn[v])<<'\n';
                }
        }
        return 0;
}
