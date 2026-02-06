#include<bits/stdc++.h>
#define N 6000010
using namespace std;int n,m;
struct T{int v[N],c,p[N][2],r[400010],t,n;void bf(int x,int l,int r){if(l==r){v[x]=l;return;}int m=l+r>>1;p[x][0]=++c;p[x][1]=++c;bf(p[x][0],l,m);bf(p[x][1],m+1,r);}
void bd(int x,int l,int r){if(l==r){v[x]=1;return;}int m=l+r>>1;p[x][0]=++c;p[x][1]=++c;bd(p[x][0],l,m);bd(p[x][1],m+1,r);}
int q(int x,int l,int r,int k){if(l==r)return v[x];int m=l+r>>1;return q(p[x][k>m],k>m?m+1:l,k>m?r:m,k);}
int g(int o,int x){return q(r[o],1,n,x);}
void u(int x,int y,int l,int r,int k,int d){if(l==r){v[x]=d;return;}int m=l+r>>1;if(k<=m){p[x][1]=p[y][1];p[x][0]=++c;u(p[x][0],p[y][0],l,m,k,d);}else{p[x][0]=p[y][0];p[x][1]=++c;u(p[x][1],p[y][1],m+1,r,k,d);}}
int mdf(int o,int k,int d){r[++t]=++c;u(r[t],r[o],1,n,k,d);return t;}}fa,dep;
int vf[200010],vd[200010],la;
int fnd(int o,int x){while(1){int t=fa.g(o,x);if(t==x)return x;x=t;}}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);cin>>n>>m;fa.n=dep.n=n;fa.r[0]=++fa.c;dep.r[0]=++dep.c;fa.bf(fa.r[0],1,n);dep.bd(dep.r[0],1,n);vf[0]=fa.t;vd[0]=dep.t;
for(int i=1,op;i<=m;i++){cin>>op;if(op==1){int a,b;cin>>a>>b;a^=la,b^=la;int x=fnd(vf[i-1],a),y=fnd(vf[i-1],b);if(x==y)vf[i]=vf[i-1],vd[i]=vd[i-1];else{int dx=dep.g(vd[i-1],x),dy=dep.g(vd[i-1],y);if(dx>dy)swap(x,y),swap(dx,dy);vf[i]=fa.mdf(vf[i-1],x,y);vd[i]=vd[i-1];if(dx==dy)vd[i]=dep.mdf(vd[i],y,dy+1);}}
else if(op==2){int k;cin>>k;k^=la;vf[i]=vf[k],vd[i]=vd[k];}
else{int a,b;cin>>a>>b;a^=la,b^=la;la=fnd(vf[i-1],a)==fnd(vf[i-1],b);cout<<la<<'\n';vf[i]=vf[i-1],vd[i]=vd[i-1];}}return 0;}
