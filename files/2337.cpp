#include <bits/stdc++.h>
using namespace std;
#define maxn 10010
int n,sz;
int ch[maxn<<7][2],v[maxn<<7],s[maxn<<7],w[maxn<<7];
inline int new_(int _v){
        ++sz;
        v[sz]=_v;w[sz]=rand();s[sz]=1;ch[sz][0]=ch[sz][1]=0;
        return sz;
}
inline void update(int rt){s[rt]=s[ch[rt][0]]+s[ch[rt][1]]+1;}
void split(int now,int k,int &x,int &y){
        if(!now)x=y=0;
        else{
                if(v[now]<=k)x=now,split(ch[now][1],k,ch[now][1],y);
                else y=now,split(ch[now][0],k,x,ch[now][0]);
                update(now);
        }
}
int merge(int x,int y){
        if(!x||!y)return x+y;
        if(w[x]<w[y]){
                ch[x][1]=merge(ch[x][1],y);
                update(x);
                return x;
        }
        else{
                ch[y][0]=merge(x,ch[y][0]);
                update(y);
                return y;
        }
}
void insert(int &root,int v){
        int x,y;
        split(root,v,x,y);
        root=merge(merge(x,new_(v)),y);
}
int query_rank(int &root,int v){
        int x,y,ret;
        split(root,v-1,x,y);
        ret=s[x]-1;
        root=merge(x,y);
        return ret;
}
void del(int &root,int v){
        int x,y,z;
        split(root,v,x,z);
        split(x,v-1,x,y);
        y=merge(ch[y][0],ch[y][1]);
        root=merge(merge(x,y),z);
}
int val[maxn<<2],ival[maxn];
void build(int rt,int l,int r){
    insert(val[rt],-2147483647);
    insert(val[rt],2147483647);
    for(int i=l;i<=r;++i)insert(val[rt],ival[i]);
    if(l==r)return;
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}
void segupdate(int rt,int l,int r,int p,int x){
    del(val[rt],ival[p]);
    insert(val[rt],x);
    if(l==r){
        ival[p]=x;
        return;
    }
    int mid=l+r>>1;
    if(p<=mid)segupdate(rt<<1,l,mid,p,x);
    else segupdate(rt<<1|1,mid+1,r,p,x);
}
int segqueryrnk(int rt,int l,int r,int ql,int qr,int x){
    if(l>qr||r<ql)return 0;
    if(l>=ql&&r<=qr)return query_rank(val[rt],x);
    int mid=l+r>>1;
    return segqueryrnk(rt<<1,l,mid,ql,qr,x)+segqueryrnk(rt<<1|1,mid+1,r,ql,qr,x);
}
int segquerykth(int ql,int qr,int k){
    int l=1,r=1000000000,ans;
    while(l<=r){
        int mid=l+r>>1;
        int tmp=segqueryrnk(1,1,n,ql,qr,mid)+1;
        if(tmp>k)r=mid-1;
        else ans=mid,l=mid+1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(1145141919);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>ival[i];
    build(1,1,n);
    string op;
    for(int i=1;i<=m;++i){
        int l,r,k;
        cin>>op;
        if(op[0]=='Q'){
            cin>>l>>r>>k;
            cout<<segquerykth(l,r,k)<<'\n';
        }
        else{
            cin>>l>>k;
            segupdate(1,1,n,l,k);
        }
    }
    return 0;
}
