#include <cstdio>
#include <iostream>
using namespace std;
#define int long long
int n,m,k,f[5010][5010],sum[5010];
signed main(){
	
	freopen("mushroom.in", "r", stdin);
	freopen("mushroom.out", "w", stdout);
    cin>>n>>m>>k;
    int tmp;
    for(int i=1;i<=n;i++)scanf("%lld",&tmp),sum[i]=sum[i-1]+tmp;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++){
            f[i][j]=f[i-1][j];
            if(j>0)for(int l=1;l<=m;l++)if(i-l>=0)f[i][j]=max(f[i][j],f[i-l][j-1]+sum[i]-sum[i-l]);
        }
    int ans=0;
    //for(int i=1;i<=n;i++){
    //    for(int j=0;j<=k;j++){
    //        printf("%d ",f[i][j]);
    //    }
    //    puts("");
    //}
    for(int i=0;i<=k;i++)ans=max(ans,f[n][i]);
    cout<<ans;
    return 0;
}
