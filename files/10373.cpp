#include <bits/stdc++.h>
using namespace std;
long long c,n,d;
long long f[300010][30],v[300010];
int fa[300010][30];
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
    cin>>c>>n>>d;
    for(int i=1;i<n;++i)scanf("%d",&fa[i][0]);
    fa[n][0]=n;
    for(int k=1;k<30;++k)for(int i=1;i<=n;++i)fa[i][k]=fa[fa[i][k-1]][k-1];
    for(int i=1;i<=n;++i)scanf("%lld",&v[i]);
    for(int i=1;i<=n;++i){
        if(i==n)f[i][0]=v[n];
        else f[i][0]=v[i]+v[fa[i][0]];
    }
    for(int k=1;k<30;++k){
        for(int i=1;i<=n;++i){
            if(fa[i][k]==i)f[i][k]=f[i][k-1];
            else f[i][k]=f[i][k-1]+f[fa[i][k-1]][k-1]-v[fa[i][k-1]];
        }
    }
    for(int u=1;u<=n;++u){
    if(v[u]>=d){printf("%d ",u);continue;}

    if(f[u][29]<d){
        printf("-1 ");
        continue;
    }

    int k=29, poi=u;
    long long current = v[u];
    while(k>=0){
        if(fa[poi][k] != poi && current + (f[poi][k] - v[poi]) < d){
            current += f[poi][k] - v[poi];
            poi = fa[poi][k];
        }
        --k;
    }
    if(fa[poi][0] != poi && current + v[fa[poi][0]] >= d)
        printf("%d ", fa[poi][0]);
    else
        printf("-1 ");
}
    return 0;
}
