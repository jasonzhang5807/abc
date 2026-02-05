#include <bits/stdc++.h>
#define maxn 5000100
using namespace std;
int rt[maxn],tmp[maxn],val[maxn],lc[maxn],rc[maxn],rbp,cnt[maxn];
void add(int rt1,int &rt2,int l,int r,int x){
    rt2=++rbp;
    cnt[rt2]=cnt[rt1]+1;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(x<=mid){
        rc[rt2]=rc[rt1];
        add(lc[rt1],lc[rt2],l,mid,x);
    }
    else{
        lc[rt2]=lc[rt1];
        add(rc[rt1],rc[rt2],mid+1,r,x);
    }
}
int query(int rt1,int rt2,int l,int r,int k){
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(cnt[lc[rt2]]-cnt[lc[rt1]]>=k) return query(lc[rt1],lc[rt2],l,mid,k);
    else return query(rc[rt1],rc[rt2],mid+1,r,k-cnt[lc[rt2]]+cnt[lc[rt1]]);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&val[i]);
    memcpy(tmp,val,sizeof(val));
    sort(tmp+1,tmp+n+1);
    int c=unique(tmp+1,tmp+n+1)-tmp-1;
    for(int i=1;i<=n;++i)
        val[i]=lower_bound(tmp+1,tmp+c+1,val[i])-tmp;
    for(int i=1;i<=n;++i)
        add(rt[i-1],rt[i],1,c,val[i]);
    while(m--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",tmp[query(rt[l-1],rt[r],1,c,k)]);
    }
    return 0;
}
