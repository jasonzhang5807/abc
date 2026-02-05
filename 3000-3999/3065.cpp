#include<bits/stdc++.h>
#define ll long long
#define N 40010
#define M 100010
using namespace std;
ll n,m,r,A[N],B[N],F[N],G[N],ans;
struct E{int u,v;bool operator<(E t){return (u!=t.u)?u<t.u:v<t.v;}}e[M];
ll rd(){
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main(){
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
    n=rd(),m=rd(),r=rd();
    for(int i=0;i<n;i++)A[i]=F[i]=rd(),ans=max(ans,A[i]);
    for(int i=0;i<m;i++)B[i]=G[i]=rd(),ans=max(ans,B[i]);
    for(int i=0;i<r;i++)e[i].u=rd()-1,e[i].v=rd()-1;
    sort(e,e+r);
    for(int i=0;i<r;i++){
        ll t1=F[e[i].u],t2=G[e[i].v];
        F[e[i].u]=max(F[e[i].u],t2+A[e[i].u]);
        G[e[i].v]=max(G[e[i].v],t1+B[e[i].v]);
        ans=max(ans,max(F[e[i].u],G[e[i].v]));
    }
    printf("%lld\n",ans);
    return 0;
}
